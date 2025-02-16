#include "Person.h"

Person::Person() : m_name(NULL), m_id(0) {} // default constructor

Person::Person(const char* name, int id) { // constructor by parameters
    SetId(id);
    SetName(name); // copy name to m_name
}

Person::Person(const Person& other) { // copy constructor
    SetId(other.GetId());
    SetName(other.GetName());
}

Person::~Person() { // destructor
    if (m_name != NULL)
        delete[] m_name; // delete all array of char
}

void Person::SetName(const char* newName) { // name setter
    if (newName != NULL) {
        int size = strlen(newName) + 1; // length of newName
        m_name = new char[size]; // new allocation to string array
        strcpy_s(m_name, size, newName); // copy newName into m_name
    }
}

void Person::SetId(int newId) { // Id setter
    if (newId > 0)
        m_id = newId;
}

#include "Person.h"

Person::Person() : m_name(NULL), m_id(0) {} // default constructor

Person::Person(const char* name, int id) { // constructor by parameters
    SetId(id);
    SetName(name); // copy name to m_name
}

Person::Person(const Person& other) { // copy constructor
    SetId(other.GetId());
    SetName(other.GetName());
}

Person::~Person() { // destructor
    if (m_name != NULL)
        delete[] m_name; // delete all array of char
}

void Person::SetName(const char* newName) { // name setter
    if (newName != NULL) {
        int size = strlen(newName) + 1; // length of newName
        m_name = new char[size]; // new allocation to string array
        strcpy_s(m_name, size, newName); // copy newName into m_name
    }
}

void Person::SetId(int newId) { // Id setter
    if (newId > 0)
        m_id = newId;
}
