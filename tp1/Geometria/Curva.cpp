#include "Curva.h"
#include "Segmento.h"

Curva::Curva(list<Coordenadas> puntosControl)
{
    this->puntosControl = puntosControl;
}

Curva::~Curva()
{
    this->puntosControl.clear();
}

void Curva::dibujar(){
    this->dibujarBezier();
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

void Curva::dibujarSplines(){
    // TODO: implementar
}

void Curva::dibujarBezier(){
    int m = 1000;
    wcPt3* curve = (wcPt3*)calloc(m,sizeof(wcPt3));
    wcPt3* control = (wcPt3*)calloc(this->puntosControl.size(), sizeof(wcPt3));
    Segmento* segmento;
    unsigned short i =0;
    Coordenadas c;
    Coordenadas* desde;
    Coordenadas* hasta;
    list<Coordenadas>::iterator it = this->puntosControl.begin();
    while (it != this->puntosControl.end()){
        c = (Coordenadas)*it;
        control[i].x = c.getX();
        control[i].y = c.getY();
        control[i].z = c.getZ();
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
    //free(curve);
    free(control);
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
      pt->x += controls[k].x  * blend;
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
