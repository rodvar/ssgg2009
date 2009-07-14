#ifndef IMAGE_H_
#define IMAGE_H_

class Image {
public:
	Image(char* ps, int w, int h);
	virtual ~Image();

	char* getPixels() { return this->pixels; }
	int getWidth() { return this->width; }
	int getHeight() { return this->height; }

private:
	char* pixels;
	int width;
	int height;
};

#endif /* IMAGE_H_ */
