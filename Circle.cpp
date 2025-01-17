#include "Circle.h"
//name=shahar solema

double Circle::getRadius() const { return m_radius; }	//returns the circle's radius
void Circle::setRadius(double r){ m_radius = r; }		//set the radius
	
Circle::Circle(double r, const char* sn ) {		//create a circle with radius=1, name=sn and center=(0,0)
	setRadius(r);
	setName(sn);	
}
Circle::Circle(const Circle & other) {							//copy constructor
	//setRadius(other.getRadius());
	setShape(other.getName(), other.getCenter());
	m_radius = other.getRadius();
}
Circle:: ~Circle() {										//destructor
}
int Circle::calcArea() const {							//returns the circle's area (rounded to int)
	return (getRadius() * getRadius() * PI);
}
int Circle::calcPerimeter() const {						//returns the circle's Perimeter (rounded to int)
	return (getRadius() * PI * 2);
}
Circle operator+(int r, const Circle& other) {	//returns a new Circle with added radius
	Circle temp(other);
	temp.setRadius(temp.getRadius() + r);
	return temp;
}
const Circle& Circle::operator=(const Circle& other){		//operator= that copies all
	setRadius(other.getRadius());
	setShape(other.getName(), other.getCenter());
	return *this;
}
const Circle& Circle::operator=(const char* name) {		//updates only the name of the shape and returns the updated shape
	setName(name);
	return *this;
}