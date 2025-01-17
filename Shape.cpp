#include "Shape.h"

//name=shahar solema

int Shape::s_totalNumOfShapes = 0;

void Shape::setName(const char* name) {//sets the shape's name
	//if (m_shapeName != NULL)
		//delete[]m_shapeName;
	m_shapeName = new char[strlen(name) + 1];
	//strcpy_s(m_shapeName, strlen(name) + 1, name);
	strcpy(m_shapeName,name);
}

void Shape::setCenter(const Point& p) { //sets the center point
	m_centerPoint.setPoint(p);
}
const char* Shape::getName() const { return m_shapeName; }						//returns the shape's name
Point Shape::getCenter() const { return m_centerPoint; }						//returns the center point
void Shape::setShape(const char* sn, const Point& other) {//set the shape's name and the center point
	setName(sn);
	m_centerPoint.setPoint(other);
	s_totalNumOfShapes++;
}
int Shape::numOfShapes() { return s_totalNumOfShapes; }
const Shape& Shape::operator=(const Shape& other) {//operator=
	if (this != &other) {//if shape are not equal
		setShape(other.getName(), other.getCenter());
	}
	return *this;
}
Shape::Shape(const char* sn ) :m_centerPoint(0, 0) {//defualt constructor
	setName(sn);
	s_totalNumOfShapes++;
}
Shape::Shape(const Shape& other){//copy constructor
	setShape(other.getName(), other.getCenter());
}
Shape:: ~Shape() {
	if (m_shapeName != NULL)
		delete[]m_shapeName;
	s_totalNumOfShapes--;
}
