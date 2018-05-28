/*
 * Student.cpp
 *
 *  Created on: Dec 23, 2016
 *      Author: alex
 */

#include "Student.h"
//#include <string.h>
using namespace std;

static int num=100;
Student::Student(): fac(GENERAL), Name(NULL) {
	ID=num;
	setName("NONE");
	num=num+1;
}
Student::Student(int id, char* name, facul faculty): ID(id),Name(NULL),fac(faculty) {
	//Name=new char[strlen(name)];
	setName(name);
}
Student::Student(const Student& alex):Name(NULL)  {
	ID=alex.ID;
	setName(alex.Name);
	fac=alex.fac;

}
Student& Student::operator =(const Student& alex){
	ID=alex.ID;

	setName(alex.Name);
	fac=alex.fac;
		return *this;
}
int Student::getID()const{
	return ID;
}
const facul Student::getFaculty()const{
	return fac;
}
char* Student::getName()const{
	return Name;
}

bool Student::setName(char* shem){
	char *temp;
	temp=new char[strlen(shem)+1];
	if (Name!=NULL)
		delete[] Name;
	Name=temp;
	strcpy(Name,shem);
	return true;
}

Student::~Student() {
	if(Name!=NULL)
		delete[] Name;

}
ostream&  operator<<(ostream& out, const Student& s){
	return s.Show(out);
	 
}

ostream& Student::Show(ostream& out) const {
	char* faculty="";
	switch (this->getFaculty()) {
	case 0: faculty=(char*)"Engineering" ;
	break;
	case 1: faculty=(char*)"Medicine";
	break;
	case 2: faculty=(char*)"Humanities";
	break;
	case 3: faculty=(char*)"Managment";
	break;
	case 4: faculty=(char*)"General";
	break;
	}

	out << "{" <<this->getID() << ", " <<this->getName() << ", "<< faculty<<"}";
	return out;
}

