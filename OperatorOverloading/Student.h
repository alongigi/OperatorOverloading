/*
 * Student.h
 *
 *  Created on: Dec 23, 2016
 *      Author: alex
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef enum Faculty { 
	ENGINEERING, MEDICINE, HUMANITIES, MANAGEMENT, GENERAL 
}facul;

class Student {

public:
	
	Student();
	Student(int ID,char* Name, facul faculty);
	Student(const Student& alex);
	Student& operator=(const Student& alex);
	int getID()const;
	char* getName() const;
	const facul getFaculty()const;
	bool setName(char* shem);

	~Student();
	friend ostream & operator<<(ostream&  out, const Student &s);
private:
		ostream& Show(ostream& out) const;
		int ID;
		char* Name;
		facul fac;
		friend class StudentSet;

};

#endif /* STUDENT_H_ */
