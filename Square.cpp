#include "Square.h"
//name=shahar solema

Square::Square(double up, double down , double right, double left , const char* sn):Quad(up, down, right, left, sn) {//constructor. center point = (0,0), name=sn
}
Square::~Square() {	//destructor
	
}
void Square::shiftX(int x) {	//shifts the center of the square by x (right and left)
	Point center = getCenter();
	center.setX(center.getX() + x);
	setCenter(center);
}
void Square::shiftY(int y) {	//shifts the center of the square by y (up and down)
	Point center = getCenter();
	center.setY(center.getY() + y);
	setCenter(center);
}