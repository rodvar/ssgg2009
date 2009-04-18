#include "Scanline.h"

#define WINDOW_HEIGHT 600 /// @todo SACAR Y CONVERTIR EN ATRIBUTO DE LA CLASE

Scanline::Scanline() {
	// TODO Auto-generated constructor stub

}

Scanline::~Scanline() {
	// TODO Auto-generated destructor stub
}

/* Inserts edge into list in order of increasing xIntersect field. */
void Scanline::insertEdge (Edge *list, Edge *edge) {
    Edge *p, *q = list;
    p = q->next;
    while (p != NULL) {
        if (edge->xIntersect < p->xIntersect)
            p = NULL;
        else {
              q = p;
              p = p->next;
        }
    }
    edge->next = q->next;
    q->next = edge;
}

/* For an index, return y-coordinate of next nonhorizontal line */
int Scanline::yNext (int k, int cnt, dcPt *pts) {
    int j;
    if ((k+1) > (cnt-1))
        j = 0;
    else
        j = k + 1;
    while (pts[k].y == pts[j].y) {
        if ((j+1) > (cnt-1))
            j = 0;
        else
            j++;
    }
    return (pts[j].y);
}

/* Store lower-y coordinate and inverse slope for each edge.  Adjust
   and store upper-y coordinate for edges that are the lower member
   of a monotically increasing or decreasing pair of edges */
void Scanline::makeEdgeRec(dcPt lower, dcPt upper, int yComp, Edge *edge, Edge *edges[])
{
    edge->dxPerScan = (float) (upper.x - lower.x) / (upper.y - lower.y);
    edge->xIntersect = lower.x;
    if (upper.y < yComp)
        edge->yUpper = upper.y - 1;
    else
        edge->yUpper = upper.y;
    insertEdge (edges[lower.y], edge);
}

void Scanline::buildEdgeList (int cnt, dcPt *pts, Edge *edges[]) {
    Edge *edge;
    dcPt v1, v2;
    int i, yPrev = pts[cnt - 2].y;
    v1.x = pts[cnt-1].x; v1.y = pts[cnt-1].y;
    for (i=0; i<cnt; i++) {
        v2 = pts[i];
        if (v1.y != v2.y) {                /* nonhorizontal line */
            edge = (Edge *) malloc (sizeof (Edge));
            if (v1.y < v2.y)               /* up-going edge      */
                makeEdgeRec (v1, v2, yNext (i, cnt, pts), edge, edges);
            else                           /* down-going edge    */
                makeEdgeRec (v2, v1, yPrev, edge, edges);
        }
        yPrev = v1.y;
        v1 = v2;
    }
}

void Scanline::buildActiveList (int scan, Edge *active, Edge *edges[])
{
    Edge *p, *q;
    p = edges[scan]->next;
    while(p) {
        q = p->next;
        insertEdge (active, p);
        p = q;
    }
}

void Scanline::deleteAfter (Edge *q) {
    Edge *p = q->next;
    q->next = p->next;
    free (p);
}

/* Delete completed edges. Update ’xIntersect’ field for others */
void Scanline::updateActiveList (int scan, Edge *active) {
    Edge *q = active, *p = active->next;
    while (p)
    if (scan >= p->yUpper) {
        p = p->next;
        deleteAfter (q);
    } else {
        p->xIntersect = p->xIntersect + p->dxPerScan;
        q = p;
        p = p->next;
    }
}

void Scanline::resortActiveList (Edge *active) {
    Edge *q, *p = active->next;
    active->next = NULL;
    while (p) {
        q = p->next;
        insertEdge (active, p);
        p = q;
    }
}

void Scanline::fillScan (int scan, Edge *active) {
    Edge *p1, *p2;
    int i;
    p1 = active->next;
    while (p1) {
        p2 = p1->next;
        for (i=p1->xIntersect; i<p2->xIntersect; i++) {
            glBegin(GL_POINTS);
                glVertex2i((int) i, scan);
            glEnd();
        }
        p1 = p2->next;
    }
}

void Scanline::scanFill (int cnt, dcPt *pts)
{
    Edge *edges[WINDOW_HEIGHT], *active;
    int i, scan;
    for (i=0; i<WINDOW_HEIGHT; i++) {
        edges[i] = (Edge *) malloc (sizeof (Edge));
        edges[i]->next = NULL;
    }
    buildEdgeList (cnt, pts, edges);
    active = (Edge *) malloc (sizeof (Edge));
    active->next = NULL;
    for (scan=0; scan<WINDOW_HEIGHT; scan++) {
        buildActiveList (scan, active, edges);
        if (active->next) {
            fillScan (scan, active);
            updateActiveList (scan, active);
            resortActiveList (active);
        }
    }

    /* Free edge records that have been malloc’ed ... */
}

