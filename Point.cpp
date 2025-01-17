#include "Point.h"
//name=shahar solema

int Point::getX() const { return m_x; }	//returns the x
int Point::getY() const { return m_y; }	//returns the y
void Point::setX(int x) { m_x = x; }//sets the x
void Point::setY(int y) { m_y = y; }//sets the y
void Point::setPoint(int x, int y) {//sets the x and y
	setX(x);
	setY(y);
}
void Point::setPoint(const Point& other) { //sets the point with other values
	setPoint(other.getX(), other.getY());
}
bool Point::operator==(const Point& other) const {		//returns true if and only if the two points are equal
	if (getX() == other.getX() && getY() == other.getY())
		return true;
	return false;
}
bool Point::operator!=(const Point& other) const {			//returns true if and only if the two points are not equal
	if (getX() != other.getX() && getY() != other.getY())
		return true;
	return false;
}
Point Point::operator+(int num) const {					//returns a new point with updated x(x+num) and y(y+num)
	Point temp(*this);
	temp.setPoint(temp.getX() + num, temp.getY() + num);
	return temp;
}
const Point& Point::operator+=(int num) {						//updates the point with x(x+num) and y(y+num) and returns the updated point
	setPoint(getX() + num, getY() + num);
	return *this;
}
Point::operator int() const {						//returns the sum of x and y
	return(getY() + getX());
}
Point Point::operator+(const Point& other) const {			//adds coordinates (x,y) and returns a new point
	Point temp(*this);
	temp.setPoint(temp.getX() + other.getX(), temp.getY() + other.getY());
	return temp;
}
Point Point::operator++(int) {//adds 1 to x and y and returns the updated point - postfix
	m_x++;
	m_y++;
	return(Point(*this + 1));
}
const Point& Point::operator++() {							//adds 1 to x and y and returns the updated point - prefix
	m_x++;
	m_y++;
	return(*this);
}
Point operator*(int num, const Point& other) {	//returns a new point with (x,y)*num
	Point temp(other);
	temp.setPoint(other.getX() * num, other.getY() * num);
	return temp;
}
Point::Point (int x, int y ) :m_x(x),m_y(y){}
Point::Point(const Point& other) {
	setPoint(other.getX(), other.getY());
}
Point::~Point() {}