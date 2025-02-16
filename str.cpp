#include "str.h"
using namespace std;

Str::Str() { // default constructor
    m_str = new char[5];
    strcpy(m_str, "none"); // copying "none" to m_str
}

Str::Str(const Str& other) { // copy constructor
    m_str = new char[strlen(other.getStr()) + 1];
    strcpy(m_str, other.getStr());
}

Str::Str(const char* str) { // constructor that copies the string
    m_str = new char[strlen(str) + 1];
    strcpy(m_str, str);
}

Str::~Str() { // destructor
    delete[] m_str;
}

bool Str::operator==(const Str& other) const { // checking if strings are equal
    return !strcmp(other.getStr(), getStr());
}

bool Str::operator!=(const Str& other) const { // checking if strings are not equal
    return strcmp(getStr(), other.getStr());
}

bool Str::operator>(const Str& other) const { // checking if left string is greater than right string by ASCII
    return strcmp(getStr(), other.getStr()) > 0;
}

bool Str::operator<(const Str& other) const { // checking if left string is smaller than right string by ASCII
    return strcmp(getStr(), other.getStr()) < 0;
}

const Str& Str::operator=(const Str& other) { // left Str gets the values of the right Str
    if (&other != this) { // checking if they are already equal
        if (m_str != NULL)
            delete[] m_str; // free spacing
        m_str = new char[strlen(other.getStr()) + 1]; // allocate new space
        strcpy(m_str, other.getStr());
    }
    return *this;
}
