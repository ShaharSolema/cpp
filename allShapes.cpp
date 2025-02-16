#include "allShapes.h"
#include "Shape.h"
#include "Circle.h"
#include "Square.h"

int allShapes::getSize() const { // returns the number of shapes
    return m_size;
}

void allShapes::addShape(Shape* newShape) { // add a new shape (deep copy) to the end of array
    int i;
    Shape** temp = new Shape*[getSize() + 1];
    for (i = 0; i < getSize(); i++) {
        temp[i] = m_arr[i];
    }
    temp[i] = newShape;
    delete[] m_arr;
    m_arr = temp;
    m_size++;
}

void allShapes::removeShape(int index) { // remove shape by index
    if (index < 0 || index >= m_size)
        return;
    int i;
    Shape** temp = new Shape*[getSize() - 1];
    delete m_arr[index];
    for (i = 0; i < index; i++) {
        temp[i] = m_arr[i];
    }
    for (i = index; i < getSize() - 1; i++) {
        temp[i] = m_arr[i + 1];
    }
    delete[] m_arr;
    m_arr = temp;
    m_size--;
}

int allShapes::totalArea() const { // returns the total area of all the shapes (rounded to int)
    double sum = 0;
    for (int i = 0; i < getSize(); i++) {
        sum += m_arr[i]->calcArea();
    }
    return (int)(sum);
}

int allShapes::totalPerimeter() const { // returns the total Perimeter of all the shapes (rounded to int)
    double sum = 0;
    for (int i = 0; i < getSize(); i++) {
        sum += m_arr[i]->calcPerimeter();
    }
    return (int)(sum);
}
