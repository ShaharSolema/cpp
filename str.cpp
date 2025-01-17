#include "str.h"
using namespace std;
//name:shahar solema
//date:02/08/2024
Str::Str() {//defualt constructor
	m_str = new char[5];
	strcpy(m_str, "none");//copying none to m_str
}
Str::Str(const Str& other) {//copying consturctor
	m_str = new char[strlen(other.getStr())+1];
	strcpy(m_str, other.getStr());
}
Str::Str(const char* str) {//consturctor that copy the string
	m_str = new char[strlen(str)+1];
	strcpy(m_str, str);
}
Str::~Str() {//distrcutor
		delete[]m_str;
}
bool Str::operator==(const Str& other) const {//checking if strings are equal
	if (!strcmp(other.getStr(), getStr()))
		return true;
	return false;
}
bool Str::operator!=(const Str& other) const {//checking if strings are nonequal
	if (strcmp(getStr(), other.getStr()))
		return true;
	return false;
}
bool Str::operator>(const Str& other) const {//checking if left string are bigger than right string by ascii.
	if (strcmp(getStr(), other.getStr()) > 0)
		return true;
	return false;

}
bool Str::operator<(const Str& other) const {//checking if left string are smaller than right string by ascii.
		if (strcmp(getStr(), other.getStr()) < 0)
			return true;
	return false;

}
const Str& Str:: operator=(const Str& other) {//left Str get the values of the right Str
	if (&other != this) {//checking if they are already equal
		if(m_str!=NULL)
			delete[]m_str;//free spacing
		m_str = new char[strlen(other.getStr())];//alocate new space;
		strcpy(m_str, other.getStr());
	}
	return *this;
}
const Str& Str:: operator=(const char* str) {////left Str get the values of the the char* str
	if (strcmp(getStr(), str)) {
		delete[]m_str;//free spacing
		m_str = new char[strlen(str)+1];//alocate new space;
		strcpy(m_str, str);
	}
	return *this;
}
Str::operator int() const {//return the len of the string
	return(strlen(getStr()));
}
char& Str::operator[](int index) const {//operator that return the letter in the index
	 if (index >= 0 && index < strlen(getStr()))//checking if index is ok
		return (m_str[index]);//return the letter of the string by refernce
}
const Str& Str:: operator++() {//adding one to every letter
	for (int i = 0; i < strlen(getStr()); i++) {
		m_str[i]+= 1;
	}
	return *this;
}
Str	Str::operator++(int) {//adding one to every letter but in differnt object
	Str temp = *this;//copying the object to new object
	++(*this);//adding one to the old object
	return temp;//return the new object
}
int Str::operator()(char ch) const {//checking if ch exist in object
	for (int i = 0; i < strlen(getStr()); i++) {
		if (getStr()[i] == ch)
			return i;//return the index of the ch
	}
	return -1;
}
Str	Str::operator+(const Str& other) const {//adding the string to another string
	char* temp = new char[strlen(other.getStr()) + strlen(getStr())+1];//new char* with the size of both objects
	strcpy(temp, getStr());
	strcat(temp, other.getStr());//adding other string to the exist string
	return Str(temp);//return the new object by using consturctor
}
const Str& Str::operator+=(const Str& other) {//adding new stringe to the exist string
	Str temp=(*this  + other);//using operator + 
	*this = temp;//using operator =
	return *this;
}
 Str operator+(const char* str, const Str& other) {//adding str to other string
	char* temp = new char[strlen(str) + strlen(other.getStr()) + 1];//new allocation
	strcpy(temp,str);
	strcat(temp, other.getStr());//adding other string to the old string
	return Str(temp);
	
}
 Str operator*(int num, const Str& other) {//copying the same string of other[ num times]
	 Str temp = other;//using = operator
	 for (int i = 2; i <= num; i++) {
		 strcat(temp.m_str, other.getStr());//adding other string num times
	 }
	 return temp;

}
