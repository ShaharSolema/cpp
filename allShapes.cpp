#include "allShapes.h"
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
//name=shahar solema

int allShapes::getSize() const {			//returns the number of shapes;
	return m_size;
}
void allShapes::addShape(Shape* newShape) {	//add a new shape (deep copy) to the end of array
	int i;
	Shape** temp = new Shape * [getSize() + 1];
	for (i = 0; i < getSize(); i++) {
		temp[i]=m_arr[i];
	}
	temp[i]=newShape;
	delete[]m_arr;
	m_arr = temp;
	m_size++;
	
}
void allShapes::removeShape(int index) {		//remove shape by index
	if (index < 0 || index >= m_size)
		return;
	int i;
	Shape** temp = new Shape * [getSize() - 1];
	delete m_arr[index];
	for (i = 0; i < index; i++) {
		temp[i] = m_arr[i];
	}
	for (i = index; i < getSize()-1; i++) {
		temp[i] = m_arr[i+1];
	}
	delete[]m_arr;
	m_arr = temp;
	m_size--;

	
}
int  allShapes::totalArea() const{//returns the total area of all the shapes (rounded to int)
	double sum = 0;
	for (int i = 0; i < getSize(); i++) {
		sum += m_arr[i]->calcArea();
	}
	return (int)(sum);
}
int  allShapes::totalPerimeter() const{			//returns the total Perimeter of all the shapes (rounded to int)
	double sum = 0;
	for (int i = 0; i < getSize(); i++) {
		sum += m_arr[i]->calcPerimeter();
	}
	return (int)(sum);
}
int allShapes::totalCircleArea() const {		//returns the total sum of circle areas (rounded to int)
	double sum = 0;
	for (int i = 0; i < getSize(); i++) {
		if (typeid(*m_arr[i]) == typeid(Circle))
			sum += m_arr[i]->calcArea();
	}
	return (sum);
}
int allShapes::totalSquarePerimeter() const{	//returns the total sum of squar Perimeter (rounded to int)
	double sum = 0;

	for (int i = 0; i < getSize(); i++) {
		if (typeid(*m_arr[i]) ==typeid(Square) )
			sum += m_arr[i]->calcPerimeter();
	}
	return (int)(sum);
}
allShapes::allShapes(){				//constructor, zero elements
	m_size = 0;
	m_arr = NULL;
}
allShapes::allShapes(const allShapes& other){	//copy c'tor - deep copy
	int i;
	if (other.getSize() == 0)
		m_arr = NULL;
	else {
		m_arr = new Shape * [other.getSize()];
		for (i = 0; i < other.getSize(); i++) {
			m_arr[i] = other.m_arr[i];
		}
	}
}
allShapes::~allShapes() {							//destructor to all elements
	delete[]m_arr;
	}
const allShapes& allShapes::operator+=(Shape* newS) {				//adds a new shape
	addShape(newS);
	return (*this);
}
Shape* allShapes::operator[](int ind) const {//returns the shape located at index ind
	if (ind < 0 || ind >= getSize())
		return NULL;
	return m_arr[ind];
}
allShapes allShapes::operator+(const allShapes& other) const {	//returns a new allShape with all elements located at this and other
	allShapes temp;
	temp.m_size = getSize() + other.getSize();
	temp.m_arr = new Shape * [getSize() + other.getSize()];
	for (int i =0 ; i < getSize(); i++)
		temp.m_arr[i]=m_arr[i];
	for (int i = getSize()-1,j=0; i < other.getSize();j++, i++)
		temp.m_arr[i]=other.m_arr[j];
	return temp;
}
allShapes::operator int() const {									//returns the number of elements	
	return m_size;
}