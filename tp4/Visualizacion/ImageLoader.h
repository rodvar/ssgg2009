#ifndef IMAGELOADER_H_
#define IMAGELOADER_H_

#include "Image.h"
#include <GL/glut.h>

class ImageLoader {
public:

	//Reads a bitmap image from file.
	static Image* loadBMP(const char* filename);

	//Levanta una textura
	static GLuint loadTexture(Image* image);

};

#endif /* IMAGELOADER_H_ */
