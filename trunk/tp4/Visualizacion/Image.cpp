#include "Image.h"

Image::Image(char* ps, int w, int h) {
	this->pixels = ps;
	this->height = h;
	this->width = w;
}

Image::~Image() {

}
