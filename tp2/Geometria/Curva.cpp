#include "Curva.h"
#include "Segmento.h"
#include "Circunferencia.h"
#include "../Interaccion/IU.h"

Curva::Curva(list<Coordenadas*> puntosControl)
{
    this->puntosControl = puntosControl;
}

Curva::~Curva()
{
    this->puntosControl.clear();
}

void Curva::dibujar(){
    if (Pantalla::getInstancia()->getModo() == BEZIER)
        this->dibujarBezier();
    else
        this->dibujarBSplines();
}

void Curva::dibujarPunteado(){
    //TODO Implementar
}

void Curva::rellenar(){
    list<Coordenadas*>::iterator it = this->puntosControl.begin();
    Coordenadas* punto;
    glBegin(GL_TRIANGLE_FAN);
        while (it != this->puntosControl.end()){
            punto = IU::getInstancia()->getEditorHoja()->mapeo(((Coordenadas*) *it)->getX(), ((Coordenadas*) *it)->getY());
            glVertex3f(punto->getX(), punto->getY(), punto->getZ());
            delete punto;
            it++;
        }
    glEnd();
}

bool Curva::contiene(int x, int y){
    return false; //TODO Implementar
}

void Curva::dibujarBezier(){
	int j=0;

    wcPt3* control = (wcPt3*)calloc(4, sizeof(wcPt3));
    Coordenadas* c;
    list<Coordenadas*>::iterator it = this->puntosControl.begin();
    while (it != this->puntosControl.end()){
        c = (Coordenadas*)*it;

		if(j==4) {
			dibujarCurvaBezier4Puntos(control);
			control[0].x = control[3].x;
			control[0].y = control[3].y;
			control[0].z = control[3].z;
			j=1;
		}

        if(j<4) {
			control[j].x = c->getX();
			control[j].y = c->getY();
			control[j].z = c->getZ();
			j++;
			it++;
        }
    }
	if(j==4) {
		dibujarCurvaBezier4Puntos(control);
	}
	free(control);
}

void Curva::dibujarCurvaBezier4Puntos(wcPt3 *control) {
    int n,t,i;
    n=3;
    t=4; // degree of polynomial = t-1

    int resolution = Motor::getInstancia()->getPasoTramoBezier();  // how many points our in our output array
    wcPt3 *out_pts;
    out_pts = new wcPt3[resolution];
	Coordenadas* mapeo;

    this->bezier(n, t, control, out_pts, resolution);

	mapeo = IU::getInstancia()->getEditorHoja()->mapeo(out_pts[0].x,out_pts[0].y);
	double anteriorX=mapeo->getX(), anteriorY=mapeo->getY();
	delete mapeo;
	for (i=0; i<resolution; i++) {
		glDisable(GL_LIGHTING);
		glBegin(GL_LINES);
			glVertex3f(anteriorX, anteriorY, 0.0);
			mapeo = IU::getInstancia()->getEditorHoja()->mapeo(out_pts[i].x,out_pts[i].y);
			glVertex3f(mapeo->getX(), mapeo->getY(), 0.0);
		glEnd();
		glEnable(GL_LIGHTING);
		anteriorX=mapeo->getX();
		anteriorY=mapeo->getY();
		delete mapeo;
	}
}

void Curva::dibujarBSplines(){
	int i;
	int npts,k,p1;

	npts = this->puntosControl.size();
	k = 4;     /* fourth order */
	p1 = Motor::getInstancia()->getPasoTramoBSpline();

	float b[3*npts + 1];  /* allows for up to 11  control vertices */
	float p[9*npts + 4];  /* allows for up to 100 points on curve */
	//float p[40];

	for (i = 1; i <= 3*npts; i++){
		b[i] = 0.;
	}

	for (i = 1; i <= 3*p1; i++){
		p[i] = 0.;
	}

	i=1;
    Coordenadas* c;
    list<Coordenadas*>::iterator it = this->puntosControl.begin();
    while (it != this->puntosControl.end()){
        c = (Coordenadas*)*it;
        b[i] = c->getX();
        b[i+1] = c->getY();
        b[i+2] = c->getZ();
        i=i+3;it++;
    }

	bsplineu(npts,k,p1,b,p);

	Coordenadas* mapeo;

	unsigned short int cantidadArboles = Motor::getInstancia()->getArbolesTramoBSpline();
	int distancia = ceil(p1/cantidadArboles);
	int contador;
	mapeo = IU::getInstancia()->getEditorSenderoPlantacion()->mapeo(p[1],p[2]);
  	double anteriorX=mapeo->getX(), anteriorY=mapeo->getY();
  	delete mapeo;
  	for (i = 1; i <= 3*p1; i=i+3) {
		glDisable(GL_LIGHTING);
		glBegin(GL_LINES);
			glVertex3f(anteriorX, anteriorY, 0.0);
			mapeo = IU::getInstancia()->getEditorSenderoPlantacion()->mapeo(p[i],p[i+1]);
			glVertex3f(mapeo->getX(), mapeo->getY(), 0.0);
		glEnd();
		glEnable(GL_LIGHTING);

		anteriorX=mapeo->getX();
		anteriorY=mapeo->getY();
		delete mapeo;

		if(i==1 || contador==distancia) {
			Motor::getInstancia()->plantarArbol(new Coordenadas(p[i],p[i+1]));
//			Circunferencia* ci = new Circunferencia(0.01,new Coordenadas(anteriorX,anteriorY));
//			Color color(1,1,1);
//			ci->setColorBorde(color);
//			ci->dibujar();
//			delete ci;
			contador=0;
		}
		contador++;
  	}

}

void Curva::bezier(int n, int t, wcPt3 *control, wcPt3 *output, int num_output) {
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
	output[num_output-1].x=control[n].x;   // put in the last point
	output[num_output-1].y=control[n].y;
	output[num_output-1].z=control[n].z;

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


void Curva::knotu(int n,int c,int x[]) {
    int nplusc,nplus2,i;

	nplusc = n + c;
	nplus2 = n + 2;

	x[1] = 0;
	for (i = 2; i <= nplusc; i++){
	    x[i] = i-1;
	}
}


void Curva::basis(int c,float t,int npts,int x[],float n[]) {
	int nplusc;
	int i,k;
	float d,e;
	float temp[36*npts];

	nplusc = npts + c;

	/* calculate the first order basis functions n[i][1]	*/

	for (i = 1; i<= nplusc-1; i++){
    	if (( t >= x[i]) && (t < x[i+1]))
			temp[i] = 1;
	    else
			temp[i] = 0;
	}

	/* calculate the higher order basis functions */

	for (k = 2; k <= c; k++){
    	for (i = 1; i <= nplusc-k; i++){
        	if (temp[i] != 0)    /* if the lower order basis function is zero skip the calculation */
           		d = ((t-x[i])*temp[i])/(x[i+k-1]-x[i]);
	        else
				d = 0;

    	    if (temp[i+1] != 0)     /* if the lower order basis function is zero skip the calculation */
        		e = ((x[i+k]-t)*temp[i+1])/(x[i+k]-x[i+1]);
	        else
    			e = 0;

    	    temp[i] = d + e;
		}
	}

	if (t == (float)x[nplusc]){		/*    pick up last point	*/
 		temp[npts] = 1;
	}

	for (i = 1; i <= npts; i++) {
    	n[i] = temp[i];
	}
}


void Curva::bsplineu(int npts,int k,int p1, float b[], float p[]) {
	int i,j,icount,jcount;
	int i1;
	int x[4*npts];		/* allows for 20 data points with basis function of order 5 */
	int nplusc;

	float step;
	float t;
	float nbasis[4*npts];
	float temp;


	nplusc = npts + k;

	/*  zero and redimension the knot vector and the basis array */

	for(i = 0; i <= npts; i++){
		 nbasis[i] = 0.;
	}

	for(i = 0; i <= nplusc; i++){
		 x[i] = 0.;
		}

	/* generate the uniform open knot vector */

	knotu(npts,k,x);

	icount = 0;

	t = k-1; /* special parameter range for periodic basis functions */
	step = ((float)((npts)-(k-1)))/((float)(p1-1));

	for (i1 = 1; i1<= p1; i1++){
		if ((float)(npts)- t < 5e-6){
			t = (float)((npts));
		}

	    basis(k,t,npts,x,nbasis);      /* generate the basis function for this value of t */

		for (j = 1; j <= 3; j++){      /* generate a point on the curve */
			jcount = j;
			p[icount+j] = 0.;

			for (i = 1; i <= npts; i++){ /* Do local matrix multiplication */
				temp = nbasis[i]*b[jcount];
			    p[icount + j] = p[icount + j] + temp;
				jcount = jcount + 3;
			}
		}
    	icount = icount + 3;
		t = t + step;
	}
}

