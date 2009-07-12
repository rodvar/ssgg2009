#include "Mar.h"
#include "../Geometria/Matematica.h"
#include "../Visualizacion/OpenGLSurfacer.h"
#include <stdlib.h>
#include <iostream>

Mar::Mar(const unsigned short dimension, const float alturaOlasMax)
{
    this->detenido = false;
    this->lineaBarrido = 0;
    this->dimension = dimension;
    this->alturaOlasMax = alturaOlasMax;
    this->alturaOlas = new float*[dimension];
    for (int i = 0 ; i < dimension ; i++)
        this->alturaOlas[i] = new float[dimension];
}

Mar::~Mar()
{
    for (int i = 0 ; i < dimension ; i++)
        delete [] this->alturaOlas[i];
    delete [] this->alturaOlas;
}

/**
 * @brief Continua el oleaje
 */
void Mar::switchCalmoInquieto(){
    this->detenido = !this->detenido;
}

void Mar::definirZonaProfunda(const float xMin,const float xMax,const float yMin, const float yMax){
    this->zonaProfunda[0] = xMin;
    this->zonaProfunda[1] = xMax;
    this->zonaProfunda[2] = yMin;
    this->zonaProfunda[3] = yMax;
}

void Mar::dibujar(){
    static unsigned short int dimension = this->dimension/2;
    float alturas[4] = {0,0,0,0};
    unsigned short int x,y,offsetY;
    offsetY = this->lineaBarrido;
    Coordenadas referencia;
    Coordenadas normal;

	if (this->lineaBarrido == this->dimension)
        this->lineaBarrido = 0;

    //OpenGLSurfacer::setAguaSalada();
    glColor3f(0.27, 0.44, 0.76);
	glBegin(GL_QUADS);
        for(int i=-dimension; i<dimension; i++){
            y = dimension + i + offsetY;
            if (y >= this->dimension){
                y %= this->dimension;
            }
            for(int j=-dimension; j<dimension;j++){
                x = j + dimension;
                this->calcularAlturas(alturas,x,y);

                referencia = Coordenadas(j+0.5f,i+0.5f,NULO);
                normal = Matematica::calcularNormalReferencia(Coordenadas((float)j,(float)i,alturas[0]),referencia);
                glNormal3f(normal.getX(),normal.getY(),normal.getZ());
                glVertex3f(j, i ,alturas[0]);
                normal = Matematica::calcularNormalReferencia(Coordenadas((float)j,(float)i,alturas[1]),referencia);
                glNormal3f(normal.getX(),normal.getY(),normal.getZ());
                glVertex3f(j+1 , i ,alturas[1]);
                normal = Matematica::calcularNormalReferencia(Coordenadas((float)j,(float)i,alturas[2]),referencia);
                glNormal3f(normal.getX(),normal.getY(),normal.getZ());
                glVertex3f(j+1 , i+1 ,alturas[2]);
                normal = Matematica::calcularNormalReferencia(Coordenadas((float)j,(float)i,alturas[3]),referencia);
                glNormal3f(normal.getX(),normal.getY(),normal.getZ());
                glVertex3f(j , i+1 ,alturas[3]);
            }
        }
	glEnd();
	//OpenGLSurfacer::setPorDefecto();

    if (!this->detenido)
        this->lineaBarrido++;
}


// Private:

// TODO: ELIMINAME!
void mostrar(float** alturaOlas, int dimension){
    for (int i = 0 ; i < dimension; i++){
        for (int j = 0 ; j < dimension; j++)
            std::cout << alturaOlas[i][j] << " ";
        std::cout << std::endl;
    }
}

void Mar::generar(){
    // Obtendo los decimales
    int random;
    int entero = (int) this->alturaOlasMax;
    int decimales = (int)((this->alturaOlasMax - floor(this->alturaOlasMax))*100);
    for (int i = 0 ; i < this->dimension; i++)
        for (int j = 0 ; j < this->dimension; j++){
            random = rand();
            this->alturaOlas[i][j] = ((float)(random%(entero+1)));
            this->alturaOlas[i][j] += (float)(random%(decimales+1))/100.0f;
        }
    this->aplicarFiltro();
}

void Mar::aplicarFiltro(){
    float filtro[DIMENSION_FILTRO][DIMENSION_FILTRO] = {
        {0.05,0.25,0.25,0.25,0.05},
        {0.25,0.50,0.50,0.50,0.25},
        {0.25,0.50,1.00,0.50,0.25},
        {0.25,0.50,0.50,0.50,0.25},
        {0.05,0.25,0.25,0.25,0.05}
    };

    for (int i = 0 ; i < this->dimension; i++)
        for (int j = 0 ; j < this->dimension; j++)
            this->alturaOlas[i][j] *= filtro[i%DIMENSION_FILTRO][j%DIMENSION_FILTRO];
}

void Mar::calcularAlturas(float* alturas,const unsigned short int x, const unsigned short int y){
    alturas[0] = this->alturaOlas[y][x];
    bool ymas1 = (y+1 < this->dimension);
    bool xmas1 = (x+1 < this->dimension);
    bool ambas = (ymas1 && xmas1);

    if (xmas1)
        alturas[1] = this->alturaOlas[y][x+1];
    else
        alturas[1] = this->alturaOlas[y][0];
    if (ambas)
        alturas[2] = this->alturaOlas[y+1][x+1];
    else
        alturas[2] = this->alturaOlas[0][0];
    if (ymas1)
        alturas[3] = this->alturaOlas[y+1][x];
    else
        alturas[3] = this->alturaOlas[0][x];
}
