/*
 * StudentSet.h
 *
 *  Created on: Dec 24, 2016
 *      Author: alex
 */

#ifndef STUDENTSET_H_
#define STUDENTSET_H_
#include "Student.h"
class StudentSet {
	int size;
	Student** set;
	ostream &Show(ostream& out)const;
	static int sizeAll;
	static StudentSet** all;
	int index;
public:
	void addprintAll(StudentSet* newSet);
	static void printAll();
	static void deleteprintAll( StudentSet* newSet );
	bool Add(const Student& s);
	StudentSet();
	StudentSet(const Student* Set,int Size);
	StudentSet& operator=(const StudentSet& sSet);
	int getSize() {return size;};
	~StudentSet();
	StudentSet operator+(const StudentSet &newSet)const;
	friend ostream& operator<<(ostream& out, const StudentSet &s);
	StudentSet& operator+=(const StudentSet &newSet);
	StudentSet operator/(const StudentSet &newSet)const;
	StudentSet& operator/=(const StudentSet &newSet);
	StudentSet operator-(const StudentSet &newSet)const;
	StudentSet& operator-=(const StudentSet &newSet);
	int operator+()const;
	Student& operator[](int index);
	const Student& operator[](int index)const;
	bool operator!=(const StudentSet& other)const;
	bool operator==(const StudentSet& other)const;

};

#endif /* STUDENTSET_H_ */
