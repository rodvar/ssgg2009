#include "Curva.h"
#include "Segmento.h"
#include "Circunferencia.h"

Curva::Curva(list<Coordenadas*> puntosControl)
{
    this->puntosControl = puntosControl;
}

Curva::~Curva()
{
    this->puntosControl.clear();
}

void Curva::dibujar(){
    this->dibujarBSplines();
}

void Curva::dibujarPunteado(){
    //TODO Implementar
}

void Curva::rellenar(){
    //TODO Implementar
}

bool Curva::contiene(int x, int y){
    return false; //TODO Implementar
}

void Curva::dibujarBSplines(){
    int n,t,i;
    n=this->puntosControl.size();
    t=4; // degree of polynomial = t-1
    i=0;

    wcPt3* control = (wcPt3*)calloc(this->puntosControl.size(), sizeof(wcPt3));
    Coordenadas* c;

    list<Coordenadas*>::iterator it = this->puntosControl.begin();
    while (it != this->puntosControl.end()){
        c = (Coordenadas*)*it;
        control[i].x = c->getX();
        control[i].y = c->getY();
        control[i].z = c->getZ();
        i++;it++;
    }

    int resolution = 10;  // how many points our in our output array
    wcPt3 *out_pts;
    out_pts = new wcPt3[resolution];

    bspline(n, t, control, out_pts, resolution);
    glColor3f(1.0, 1.0, 1.0);

	Circunferencia* circ;
  	for (i=0; i<n; i++) {
  		circ = new Circunferencia(0.01,new Coordenadas(control[i].x,control[i].y));
  		Color color(1,1,1);
  		circ->setColorBorde(color);
  		circ->dibujar();
        delete circ;
  	}

  	double anteriorX=out_pts[0].x, anteriorY=out_pts[0].y;
  	for (i=0; i<resolution; i++) {
  		glDisable(GL_LIGHTING);
  		glBegin(GL_LINES);
  			glVertex3f(anteriorX, anteriorY, 0.0);
  			glVertex3f(out_pts[i].x, out_pts[i].y, 0.0);
  		glEnd();
  		glEnable(GL_LIGHTING);
  		anteriorX=out_pts[i].x;
  		anteriorY=out_pts[i].y;
  	}
  	free(control);

}

void Curva::dibujarBezier(){
    int m = 1000;
    wcPt3* curve = (wcPt3*)calloc(m,sizeof(wcPt3));
    wcPt3* control = (wcPt3*)calloc(this->puntosControl.size(), sizeof(wcPt3));
    Segmento* segmento;
    unsigned short i =0;
    Coordenadas* c;
    Coordenadas* desde;
    Coordenadas* hasta;
    list<Coordenadas*>::iterator it = this->puntosControl.begin();
    while (it != this->puntosControl.end()){
        c = (Coordenadas*)*it;
        control[i].x = c->getX();
        control[i].y = c->getY();
        control[i].z = c->getZ();
        i++;it++;
    }
    this->bezier(control, this->puntosControl.size(), m, curve);
    for (i =0; i < m; i+=2){
        desde = new Coordenadas(curve[i].x,curve[i].y,curve[i].z);
        hasta = new Coordenadas(curve[i+1].x,curve[i+1].y,curve[i+1].z);
        segmento = new Segmento(desde,hasta);
        segmento->dibujar();
        delete segmento;
    }
    //free(curve); // Revisar esto
    free(control);
}

void Curva::bspline(int n, int t, wcPt3 *control, wcPt3 *output, int num_output) {
	int *u;
	double increment,interval;
	wcPt3 calcxyz;
	int output_index;

	u=new int[n+t+1];
	compute_intervals(u, n, t);

	increment=(double) (n-t+2)/(num_output-1);  // how much parameter goes up each time
	interval=0;

	for (output_index=0; output_index<num_output-1; output_index++) {
		compute_point(u, n, t, interval, control, &calcxyz);
		output[output_index].x = calcxyz.x;
		output[output_index].y = calcxyz.y;
		output[output_index].z = calcxyz.z;
		interval = interval + increment;  // increment our parameter
	}
	output[num_output-1].x=control[n-1].x;   // put in the last point
	output[num_output-1].y=control[n-1].y;
	output[num_output-1].z=control[n-1].z;

	delete u;
}

double Curva::blend(int k, int t, int *u, double v)  {
	double value;

	// caso base para la recursion
	if (t==1) {
		if ((u[k]<=v) && (v<u[k+1])) {
			value=1;
		} else {
			value=0;
		}
	} else {
		// chequea division por cero
		if ((u[k+t-1]==u[k]) && (u[k+t]==u[k+1])) {
			value = 0;
		} else {
			// Si un denominador es cero, usa el otro
			if (u[k+t-1]==u[k]) {
				value = (u[k+t] - v) / (u[k+t] - u[k+1]) * blend(k+1, t-1, u, v);
			} else {
				if (u[k+t]==u[k+1]) {
					value = (v - u[k]) / (u[k+t-1] - u[k]) * blend(k, t-1, u, v);
				} else {
					value = (v - u[k]) / (u[k+t-1] - u[k]) * blend(k, t-1, u, v) +
					(u[k+t] - v) / (u[k+t] - u[k+1]) * blend(k+1, t-1, u, v);
				}
			}
		}
	}
	return value;
}


void Curva::compute_intervals(int *u, int n, int t) {
	int j;

	for (j=0; j<=n+t; j++) {
		if (j<t) {
			u[j]=0;
		} else {
			if ((t<=j) && (j<=n)) {
				u[j]=j-t+1;
			} else {
				if (j>n) {
					// si n-t=-2 hay un inconveniente, todo se va a 0
					u[j]=n-t+2;
				}
			}
		}
	}
}

void Curva::compute_point(int *u, int n, int t, double v, wcPt3 *control, wcPt3 *output) {
	int k;
	double temp;

	// initialize the variables that will hold our outputted point
	output->x=0;
	output->y=0;
	output->z=0;

	for (k=0; k<=n; k++) {
		temp = blend(k,t,u,v);  // same blend is used for each dimension coordinate
		output->x = output->x + (control[k]).x * temp;
		output->y = output->y + (control[k]).y * temp;
		output->z = output->z + (control[k]).z * temp;
	}
}

void Curva::computeCoefficients(int n, int* c){
   int k, i;
   for (k=0; k<=n; k++){
      /* Compute n!/ (k!(n-k)!)*/
      c[k] = 1;
   for (i=n; i >= k + 1; i--)
       c[k] *= i;
    for(i=n-k; i>=2; i--)
        c[k] /= i;
   }
}

void Curva::computePoint(float u, wcPt3* pt,  int ncontrols, wcPt3* controls, int* c){
     int k , n = ncontrols - 1;
     float blend;

     pt->x = 0.0; pt->y = 0.0; pt->z = 0.0;

 /*Add in influence of each control point*/
   for (k=0; k < ncontrols; k++) {
      blend = c[k] * powf(u,k) * powf(1-u,n-k);
      pt->x += controls[k].x * blend;
      pt->y += controls[k].y * blend;
      pt->z += controls[k].z * blend;
    }
}


void Curva::bezier(wcPt3* controls, int ncontrols, int m, wcPt3* curve)
{
   /* Allocate space for the coefficients */
   int* c = (int*) malloc (ncontrols* sizeof (int));
   int i;

   computeCoefficients (ncontrols-1, c);
   for (i=0; i<= m ; i++)
      computePoint ( i / (float) m, &curve[i], ncontrols, controls, c);
   free (c);
}
