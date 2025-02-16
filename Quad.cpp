#include "Quad.h"

Quad::Quad(double up, double down, double right, double left, const char* sn) 
    : m_up(up), m_down(down), m_right(right), m_left(left) { // constructor. center point = (0,0), name=sn
    setName(sn);
}

Quad::Quad(const Quad& other) { // copy constructor
    setShape(other.getName(), other.getCenter());
    m_up = other.m_up;
    m_down = other.m_down;
    m_right = other.m_right;
    m_left = other.m_left;
}

Quad::~Quad() { // destructor
}

int Quad::calcArea() const { // returns the quad's area (right*up) (rounded to int)
    return ((int)(m_right * m_up));
}

int Quad::calcPerimeter() const { // returns the quad's Perimeter (the sum of the four ribs) (rounded to int)
    return ((int)(m_right + m_up + m_left + m_down));
}
