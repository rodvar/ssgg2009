#ifndef SCANLINE_H_
#define SCANLINE_H_

#include <cstdlib>
#include <GL/glut.h>
#include "../Geometria/Coordenadas.h"

typedef struct tEdge {
    int yUpper;
    float xIntersect, dxPerScan;
    struct tEdge *next;
} Edge;

typedef struct tdcPt {
    int x;
    int y;
} dcPt;

class Scanline {
public:
	Scanline();
	virtual ~Scanline();

	void scanFill(int cnt, dcPt *pts);

private:

	void insertEdge (Edge *list, Edge *edge);
	int yNext (int k, int cnt, dcPt *pts);
	void makeEdgeRec(dcPt lower, dcPt upper, int yComp, Edge *edge, Edge *edges[]);
	void buildEdgeList (int cnt, dcPt *pts, Edge *edges[]);
	void buildActiveList (int scan, Edge *active, Edge *edges[]);
	void deleteAfter (Edge *q);
	void updateActiveList (int scan, Edge *active);
	void resortActiveList (Edge *active);
	void fillScan (int scan, Edge *active);

};

#endif /* SCANLINE_H_ */
