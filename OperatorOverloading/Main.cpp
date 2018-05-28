//============================================================================
// Name        : Main.cpp
// Author      : ise
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <iostream>
#include "StudentSet.h"
#include "string.h"

using namespace std;




int main() {
/*
	Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);


		Student studentArray1[] = {s1, s2, s3, s4};
		Student studentArray2[] = {s3, s4, s5, s6};
		StudentSet set2(studentArray2, 4);
		Student answerArray1[] = {s1, s2, s3, s5, s6};
		StudentSet expected1(answerArray1, 5);
		StudentSet set7(studentArray1, 4);
		StudentSet tempSet1 = set7;
		set7+=set2;*/

	int allAnswers[50];
	for (int i = 0 ; i < sizeof(allAnswers)/sizeof(int) ; i++)
	{
		allAnswers[i] = 0;
	}
	try {
		Student* array = new Student[5];
		for (int i = 0 ; i < 5 ; i++)
		{
			if (array[i].getID() == 100+i && array[i].getFaculty() == GENERAL && strcmp(array[i].getName(),"NONE")==0) {
				cout << "Success: 1. Student Default Constructor Call #" << i << endl;
				allAnswers[0] = 1; }
			else {
				cout << "Fail: 1. Student Default Constructor Call #" << i  << endl;
				allAnswers[0] = 0;
			}
		}
		delete[] array;
	}
	catch (exception& e)
	{
		cout << "Fail: 1. Student Default Constructor Call: " << e.what() << endl;
	}
	try {
		Student* s1 = new Student(200, "Carmel", ENGINEERING);
		if (s1->getID() == 200 && s1->getFaculty() == ENGINEERING && strcmp(s1->getName(),"Carmel")==0) {
			cout << "Success: 2. Student Constructor Call" << endl;
			allAnswers[1] = 1;
		}
		else
		{
			cout << "Fail: 2. Student Constructor Call: (Expected: {200, Carmel, Engineering} , Actual: " << *s1 << ")" << endl;

		}
		delete s1;
	}
	catch (exception& e)
	{
		cout << "Fail: 2. Student Constructor Call:  " << e.what() << endl;
	}
	try{
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(s2);
		if (s3.getID() == 201 && s3.getFaculty() == HUMANITIES && strcmp(s3.getName(),"Ofer")==0) {
			cout << "Success: 3. Student Copy Constructor Call" << endl;
			allAnswers[2] = 1;
		}
		else
		{
			cout << "Fail: 3. Student Copy Constructor Call: (Expected: {201, Ofer, Humanities} , Actual: " << s3 << ")" << endl;

		}
	}
	catch (exception& e)
	{
		cout << "Fail: 3. Student Copy Constructor Call: " << e.what() << endl;
	}
	try {
		Student s4(201, "Ofer", HUMANITIES);
		Student s5 = s4;
		if (s5.getID() == 201 && s5.getFaculty() == HUMANITIES && strcmp(s5.getName(),"Ofer")==0) {
			cout << "Success: 4. Student '=' operator overloading" << endl;
			allAnswers[3] = 1;
		}
		else
			cout << "Fail: 4. Student '=' operator overloading: (Expected: {201, Ofer, Humanities} , Actual: " << s5 << ")" << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 4. Student '=' operator overloading: " << e.what() << endl;
	}
	try {
		StudentSet set1;
		if (set1.getSize() != 0) {
			cout << "Fail: 5. StudentSet Default constructor - Didn't return an empty set" << endl;

		}
		else {
			cout << "Success: 5. StudentSet Default constructor" << endl;
			allAnswers[4] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Fail: 5. StudentSet Default constructor: " << e.what() << endl;
	}
	try {
		Student s6(200, "Carmel", ENGINEERING);
		Student s7(201, "Ofer", HUMANITIES);
		Student s8(202, "Noam", MANAGEMENT);
		Student s9 = s8;
		Student studentArray[] = {s6, s7, s8, s9};
		StudentSet set2(studentArray, 4);
		if (set2.getSize() != 3) {
			cout << "Fail: 6. StudentSet constructor:  set size should be 3, Actual: " << set2.getSize() << endl;
			}
		else {
			cout << "Success: 6. StudentSet  constructor" << endl;
			allAnswers[5] = 1;
		}

	}
	catch (exception& e) {
		cout << "Fail: 6. StudentSet constructor: " << e.what() << endl;
	}
	try {
		Student s6(200, "Carmel", ENGINEERING);
		Student s7(201, "Ofer", HUMANITIES);
		Student s8(202, "Noam", MANAGEMENT);
		Student s9 = s8;
		Student studentArray[] = {s6, s7, s8, s9};
		StudentSet set1;
		StudentSet set2(studentArray, 4);
		if (set1 == set2) {
			cout << "Fail: 7. StudentSet '==' operator overloading - returned TRUE for different sets ( " << set1 << " , " << set2 << " )" << endl;
			 }
		else {
			cout << "Success: 7. StudentSet '==' operator overloading" << endl;
			allAnswers[6] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Fail: 7. StudentSet '==' operator overloading: " << e.what() << endl;
	}

	try {
		Student s6(200, "Carmel", ENGINEERING);
		Student s7(201, "Ofer", HUMANITIES);
		Student s8(202, "Noam", MANAGEMENT);
		Student s9 = s8;
		Student studentArray[] = {s6, s7, s8, s9};
		StudentSet set1;
		StudentSet set2(studentArray, 4);
		if (set1 != set2) {
			cout << "Success: 8. StudentSet '!=' operator overloading" << endl;
			allAnswers[7] = 1;
		}
		else
			cout << "Fail: 8. StudentSet '!=' operator overloading -returned FALSE for different sets ( " << set1 << " , " << set2 << " )" << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 8. StudentSet '!=' operator overloading: " << e.what() << endl;
	}
	try {
		Student s6(200, "Carmel", ENGINEERING);
		Student s7(201, "Ofer", HUMANITIES);
		Student s8(202, "Noam", MANAGEMENT);
		Student s9 = s8;
		Student studentArray[] = {s6, s7, s8, s9};
		StudentSet set2(studentArray, 4);
		StudentSet set3(studentArray, 4);
		if (set3 == set2) {
			cout << "Success: 9. StudentSet '==' operator overloading" << endl;
			allAnswers[8] = 1;
		}
		else
			cout << "Failed: 9. StudentSet '==' operator overloading - returned FALSE for equal sets ( " << set2 << " , " << set3 << " )" << endl;
	}
	catch (exception& e)
	{
		cout << "Failed: 9. StudentSet '==' operator overloading: " << e.what() << endl;
	}
	try {
		Student s6(200, "Carmel", ENGINEERING);
		Student s7(201, "Ofer", HUMANITIES);
		Student s8(202, "Noam", MANAGEMENT);
		Student s9 = s8;
		Student s10(203, "Dolores", MEDICINE);
		Student studentArray[] = {s6, s7, s8, s9};
		StudentSet set3(studentArray, 4);
		set3[0] = s10;
		if (set3[0].getID() == 203 && set3[0].getFaculty() == MEDICINE && strcmp(set3[0].getName(),"Dolores")==0) {
			cout << "Success: 10. Student '=', StudentSet '[]' operator overloading" << endl;
			allAnswers[9] = 1; }
		else
		{
			cout << "Fail: 10. Student '=', StudentSet '[]' operator overloading (Expected: {203, Dolores, Medicine} , Actual: " << set3[0] << ")" << endl;

		}
	}
	catch (exception& e)
	{
		cout << "Fail: 10. Student '=', StudentSet '[]' operator overloading: " << e.what() << endl;
	}
	try {
		Student s6(200, "Carmel", ENGINEERING);
		Student s7(201, "Ofer", HUMANITIES);
		Student s8(202, "Noam", MANAGEMENT);
		Student s9 = s8;
		Student s10(203, "Dolores", MEDICINE);
		Student studentArray[] = {s6, s7, s8, s9};
		StudentSet set2(studentArray, 4);
		StudentSet set3(studentArray, 4);
		set3[0] = s10;
		if (set3 == set2) {
			cout << "Fail: 11. StudentSet '==' operator overloading: Failed - returned TRUE for different sets ( " << set2 << " , " << set3 << " )" << endl;

		}
		else {
			cout << "Success: 11. StudentSet '==' operator overloading" << endl;
			allAnswers[10] = 1;
		}

	}
	catch (exception& e)
	{
		cout << "Success: 11. StudentSet '==' operator overloading: " << e.what() << endl;
	}
	try {
		Student s6(200, "Carmel", ENGINEERING);
		Student s7(201, "Ofer", HUMANITIES);
		Student s8(202, "Noam", MANAGEMENT);
		Student s9 = s8;
		Student s10(203, "Dolores", MEDICINE);
		Student studentArray[] = {s6, s7, s8, s9};
		StudentSet set2(studentArray, 4);
		StudentSet set3(studentArray, 4);
		set3[0] = s10;
		if (set3 != set2) {
			cout << "Success: 12. StudentSet '!=' operator overloading" << endl;
			allAnswers[11] = 1;
		}
		else
			cout << "Fail: 12. StudentSet '!=' operator overloading - returned FALSE for different sets ( " << set2 << " , " << set3 << " )" << endl;

	}
	catch (exception& e)
	{
		cout << "Fail: 12. StudentSet '!=' operator overloading: " << e.what() << endl;
	}
	try {
		Student s6(200, "Carmel", ENGINEERING);
		Student s7(201, "Ofer", HUMANITIES);
		Student s8(202, "Noam", MANAGEMENT);
		Student studentArray[] = {s6, s7, s8};
		StudentSet set4(studentArray, 0);
		if (set4.getSize() != 0) {
			cout << "Fail: 13. StudentSet constructor with 0 members - set size should be 0, Actual: " << set4.getSize() << endl;
		}
		else {
			cout << "Success: 13. StudentSet constructor with 0 members" << endl;
			allAnswers[12] = 1;
		}

	}
	catch (exception& e)
	{
		cout << "Fail: 13. StudentSet '!=' operator overloading: " << e.what() << endl;
	}
	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);
		Student studentArray1[] = {s1, s2, s3, s4};
		Student studentArray2[] = {s3, s4, s5, s6};
		StudentSet set1(studentArray1, 4);
		StudentSet set2(studentArray2, 4);
		Student answerArray1[] = {s1, s2, s3, s5, s6};
		StudentSet expected1(answerArray1, 5);
		StudentSet answer = set1 + set2;
		if (answer == expected1 && !(answer != expected1)) {
			cout << "Success: 14. UnionTest (+) #1 " << set1 << " + " << set2  << endl;
			allAnswers[13] = 1;
		}
		else
			cout << "Fail: 14. UnionTest (+) #1 " << set1 << " + " << set2  << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 14. UnionTest (+) #1: " << e.what() << endl;
	}
	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);
		Student studentArray1[] = {s1, s2, s3, s4};
		StudentSet set1(studentArray1, 4);
		StudentSet set3;
		Student answerArray1[] = {s1, s2, s3, s5, s6};
		StudentSet expected1(answerArray1, 5);
		StudentSet answer = set1 + set3;
		if (answer != set1 || !(answer == set1))
			cout << "Fail: 15. UnionTest (+) #2 " << set1 << " + " << set3  << endl;
		else {
			cout << "Success: 15. UnionTest (+) #2 " << set1 << " + " << set3  << endl;
			allAnswers[14] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Success: 15. UnionTest (+) #2: " << e.what() << endl;
	}
	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);
		Student studentArray1[] = {s1, s2, s3, s4};
		StudentSet set1(studentArray1, 4);
		StudentSet set3;
		Student answerArray1[] = {s1, s2, s3, s5, s6};
		StudentSet answer = set3 + set1;
		if (answer != set1 || !(answer == set1))
			cout << "Fail: 16. UnionTest (+) #3 " << set3 << " + " << set1  << endl;
		else {
			cout << "Success: 16. UnionTest (+) #3 " << set3 << " + " << set1  << endl;
			allAnswers[15] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Success: 16. UnionTest (+) #3: " << e.what() << endl;
	}
	try
	{
		StudentSet set3;
		StudentSet answer = set3 + set3;
		if (answer == set3 && !(answer != set3)) {
			cout << "Success: 17. UnionTest (+) #4 " << set3 << " + " << set3  << endl;
			allAnswers[16] = 1;
		}
		else
			cout << "Fail: 17. UnionTest (+) #4 " << set3 << " + " << set3  << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 17. UnionTest (+) #4: " << e.what() << endl;
	}
	try
	{
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);
		Student studentArray2[] = {s3, s4, s5, s6};
		StudentSet set2(studentArray2, 4);
		StudentSet answer = set2 + set2;
		if (answer != set2 || !(answer == set2))
			cout << "Fail: 18. UnionTest (+) #5 " << set2 << " + " << set2  << endl;
		else {
			cout << "Success: 18. UnionTest (+) #5 " << set2 << " + " << set2  << endl;
			allAnswers[17] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Fail: 18. UnionTest (+) #5: " << e.what() << endl;
	}
	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);

		Student studentArray1[] = {s1, s2, s3, s4};
		Student studentArray2[] = {s3, s4, s5, s6};
		StudentSet set1(studentArray1, 4);
		StudentSet set2(studentArray2, 4);

		Student answerArray2[] = {s1, s2};
		StudentSet expected2(answerArray2, 2);
		StudentSet answer = set1 - set2;
		if (answer == expected2 && !(answer != expected2)) {
			cout << "Success: 19. DifferenceTest (-) #1 " << set1 << " - " << set2  << endl;
			allAnswers[18] = 1;
		}
		else
			cout << "Fail: 19. DifferenceTest (-) #1 " << set1 << " - " << set2  << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 19. DifferenceTest (-) #1: " << e.what() << endl;
	}
	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student studentArray1[] = {s1, s2, s3, s4};
		StudentSet set1(studentArray1, 4);
		StudentSet set3;
		StudentSet answer = set1 - set3;
		if (answer != set1 || !(answer == set1))
			cout << "Fail: 20. DifferenceTest (-) #2 " << set1 << " - " << set3  << endl;
		else {
			cout << "Success: 20. DifferenceTest (-) #2 " << set1 << " - " << set3  << endl;
			allAnswers[19] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Fail: 20. DifferenceTest (-) #2 : " << e.what() << endl;
	}

	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student studentArray1[] = {s1, s2, s3, s4};
		StudentSet set1(studentArray1, 4);
		StudentSet set3;
		StudentSet answer = set3 - set1;
		if (answer == set3 && !(answer != set3)) {
			cout << "Success: 21. DifferenceTest (-) #3 " << set3 << " - " << set1  << endl;
			allAnswers[20] = 1;
		}
		else
			cout << "Fail: 21. DifferenceTest (-) #3 " << set3 << " - " << set1  << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 21. DifferenceTest (-) #3 : " << e.what() << endl;
	}

	try
	{
		StudentSet set3;
		StudentSet set4;
		StudentSet answer = set3 - set4;
		if (answer != set3 || !(answer == set3))
			cout << "Fail: 22. DifferenceTest (-) #4 " << set3 << " - " << set4  << endl;
		else {
			cout << "Success: 22. DifferenceTest (-) #4 " << set3 << " - " << set4  << endl;
			allAnswers[21] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Fail: 21. DifferenceTest (-) #3 : " << e.what() << endl;
	}
	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);
		Student s7(205, "Maeve", MANAGEMENT);
		Student studentArray1[] = {s1, s2, s3, s4};
		StudentSet set1(studentArray1, 4);
		Student studentArray3[] = {s5, s6, s7, s6};
		StudentSet set5(studentArray3, 4);
		StudentSet answer = set1 - set5;
		if (answer == set1 && !(answer != set1)) {
			cout << "Success: 23. DifferenceTest (-) #5 " << set1 << " - " << set5  << endl;
			allAnswers[22] = 1;
		}
		else
			cout << "Fail: 23. DifferenceTest (-) #5 " << set1 << " - " << set5  << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 23. DifferenceTest (-) #5 : " << e.what() << endl;
	}
	try
	{
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);
		Student s7(205, "Maeve", MANAGEMENT);
		StudentSet set3;
		Student studentArray3[] = {s5, s6, s7, s6};
		Student studentArray4[] = {s7, s5, s6, s6, s6};
		StudentSet set5(studentArray3, 4);
		StudentSet set6(studentArray4, 5);
		StudentSet answer = set6 - set5;
		if (answer != set3 || !(answer == set3))
			cout << "Fail: 24. DifferenceTest (-) #6 " << set6 << " - " << set5  << endl;
		else {
			cout << "Success: 24. DifferenceTest (-) #6 " << set6 << " - " << set5  << endl;
			allAnswers[23] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Success: 24. DifferenceTest (-) #6 : " << e.what() << endl;
	}
	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student studentArray1[] = {s1, s2, s3, s4};
		StudentSet set1(studentArray1, 4);
		StudentSet set3;
		StudentSet expected3(studentArray1, 4);
		StudentSet tempSet1 = set1;
		set1+= set3;
		if (set1 == expected3 && !(set1 != expected3)) {
			cout << "Success: 25. UnionTest (+=) #1 " << tempSet1 << " += " << set3  << endl;
			allAnswers[24] = 1;
		}
		else
			cout << "Fail: 25. UnionTest (+=) #1 " << tempSet1 << " += " << set3  << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 25. UnionTest (+=) #1 : " << e.what() << endl;
	}
	try
	{
		StudentSet set3;
		StudentSet set4;
		StudentSet tempSet3 = set3;
		set3 += set4;
		if (set3 != set4 || !(set3 == set4))
			cout << "Fail: 26. UnionTest (+=) #2 " << tempSet3 << " += " << set4  << endl;
		else {
			cout << "Success: 26. UnionTest (+=) #2 " << tempSet3 << " += " << set4  << endl;
			allAnswers[25] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Success: 26. UnionTest (+=) #2  : " << e.what() << endl;
	}
	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student studentArray1[] = {s1, s2, s3, s4};
		StudentSet set1(studentArray1, 4);
		StudentSet set3;
		StudentSet expected3(studentArray1, 4);
		StudentSet tempSet3 = set3;
		set3+= set1;
		if (set3 == expected3 && !(set3 != expected3)) {
			cout << "Success: 27. UnionTest (+=) #3 " << tempSet3 << " += " << set1  << endl;
			allAnswers[26] = 1;
		}
		else
			cout << "Fail: 27. UnionTest (+=) #3 " << tempSet3 << " += " << set1  << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 27. UnionTest (+=) #3  : " << e.what() << endl;
	}
	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);


		Student studentArray1[] = {s1, s2, s3, s4};
		Student studentArray2[] = {s3, s4, s5, s6};
		StudentSet set2(studentArray2, 4);
		Student answerArray1[] = {s1, s2, s3, s5, s6};
		StudentSet expected1(answerArray1, 5);
		StudentSet set7(studentArray1, 4);
		StudentSet tempSet1 = set7;
		set7+=set2;
		if (set7 != expected1 || !(set7 == expected1))
			cout << "Fail: 28. UnionTest (+=) #4 " << tempSet1 << " += " << set2  << endl;
		else
		{
			cout << "Success: 28. UnionTest (+=) #4 " << tempSet1 << " += " << set2  << endl;
			allAnswers[27] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Success: 28. UnionTest (+=) #4  : " << e.what() << endl;
	}
	try
	{
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);
		Student studentArray2[] = {s3, s4, s5, s6};
		StudentSet set2(studentArray2, 4);
		StudentSet tempSet2(studentArray2, 4);
		set2+= set2;
		if (set2 == tempSet2 && !(set2 != tempSet2)) {
			cout << "Success: 29. UnionTest (+=) #5 " << tempSet2 << " += " << tempSet2  << endl;
			allAnswers[29] = 1;
		}
		else
			cout << "Fail: 29. UnionTest (+=) #5 " << tempSet2 << " += " << tempSet2  << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 29. UnionTest (+=) #5  : " << e.what() << endl;
	}
	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);

		Student studentArray1[] = {s1, s2, s3, s4};
		Student studentArray2[] = {s3, s4, s5, s6};
		StudentSet set1(studentArray1, 4);
		StudentSet set2(studentArray2, 4);

		Student answerArray2[] = {s1, s2};
		StudentSet expected2(answerArray2, 2);
		StudentSet temp = set1;
		set1 -= set2;
		if (set1 == expected2 && !(set1 != expected2)) {
			cout << "Success: 30. DifferenceTest (-=) #1 " << temp << " -= " << set2  << endl;
			allAnswers[29] = 1;
		}
		else
			cout << "Fail: 30. DifferenceTest (-=) #1 " << temp << " -= " << set2  << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 30. DifferenceTest (-=) #1: " << e.what() << endl;
	}
	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student studentArray1[] = {s1, s2, s3, s4};
		StudentSet set1(studentArray1, 4);
		StudentSet set3;
		StudentSet temp = set1;
		set1 -= set3;
		if (set1 != temp || !(set1 == temp))
			cout << "Fail: 31. DifferenceTest (-=) #2 " << temp << " -= " << set3  << endl;
		else {
			cout << "Success: 31. DifferenceTest (-=) #2 " << temp << " -= " << set3  << endl;
			allAnswers[30] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Fail: 31. DifferenceTest (-=) #2 : " << e.what() << endl;
	}

	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student studentArray1[] = {s1, s2, s3, s4};
		StudentSet set1(studentArray1, 4);
		StudentSet set3;
		StudentSet emptySet;
		set3 -= set1;
		if (set3 == emptySet && !(set3 != emptySet)) {
			cout << "Success: 32. DifferenceTest (-=) #3 " << emptySet << " -= " << set1  << endl;
			allAnswers[31] = 1;
		}
		else
			cout << "Fail: 32. DifferenceTest (-=) #3 " << emptySet << " -= " << set1  << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 32. DifferenceTest (-=) #3 : " << e.what() << endl;
	}

	try
	{
		StudentSet set3;
		StudentSet set4;
		set3 -= set4;
		if (set3 != set4 || !(set3 == set4))
			cout << "Fail: 33. DifferenceTest (-=) #4 " << set4 << " -= " << set4  << endl;
		else {
			cout << "Success: 33. DifferenceTest (-=) #4 " << set4 << " -= " << set4  << endl;
			allAnswers[32] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Fail: 33. DifferenceTest (-=) #3 : " << e.what() << endl;
	}
	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);
		Student s7(205, "Maeve", MANAGEMENT);
		Student studentArray1[] = {s1, s2, s3, s4};
		StudentSet set1(studentArray1, 4);
		Student studentArray3[] = {s5, s6, s7, s6};
		StudentSet set5(studentArray3, 4);
		Student answerArray[] = {s1, s2, s3, s4};
		StudentSet expected(answerArray, 4);
		set1 -= set5;
		if (set1 == expected && !(set1 != expected)) {
			cout << "Success: 34. DifferenceTest (-=) #5 " << expected << " -= " << set5  << endl;
			allAnswers[33] = 1;
		}
		else
			cout << "Fail: 34. DifferenceTest (-=) #5 " << expected << " -= " << set5  << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 34. DifferenceTest (-=) #5 : " << e.what() << endl;
	}
	try
	{
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);
		Student s7(205, "Maeve", MANAGEMENT);
		StudentSet set3;
		Student studentArray3[] = {s5, s6, s7, s6};
		Student studentArray4[] = {s7, s5, s6, s6, s6};
		StudentSet set5(studentArray3, 4);
		StudentSet set6(studentArray4, 5);
		StudentSet temp = set6;
		set6 -= set5;
		StudentSet emptySet;
		if (set6 != emptySet || !(set6 == emptySet))
			cout << "Fail: 35. DifferenceTest (-=) #6 " << temp << " -= " << set5  << endl;
		else {
			cout << "Success: 35. DifferenceTest (-=) #6 " << temp << " -= " << set5  << endl;
			allAnswers[34] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Success: 35. DifferenceTest (-=) #6 : " << e.what() << endl;
	}



	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);

		Student studentArray1[] = {s1, s2, s3, s4};
		Student studentArray2[] = {s3, s4, s5, s6};
		StudentSet set1(studentArray1, 4);
		StudentSet set2(studentArray2, 4);

		Student answerArray2[] = {s3};
		StudentSet expected2(answerArray2, 1);
		StudentSet temp = set1;
		set1 /= set2;
		if (set1 == expected2 && !(set1 != expected2)) {
			cout << "Success: 36. conjunctionTest (/=) #1 " << temp << " /= " << set2  << endl;
			allAnswers[35] = 1;
		}
		else
			cout << "Fail: 36. conjunctionTest (/=) #1 " << temp << " /= " << set2  << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 36. conjunctionTest (/=) #1: " << e.what() << endl;
	}
	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student studentArray1[] = {s1, s2, s3, s4};
		StudentSet set1(studentArray1, 4);
		StudentSet set3;
		StudentSet temp = set1;
		set1 /= set3;
		if (set1 != set3 || !(set1 == set3))
			cout << "Fail: 37. conjunctionTest (/=) #2 " << temp << " /= " << set3  << endl;
		else {
			cout << "Success: 37. conjunctionTest (/=) #2 " << temp << " /= " << set3  << endl;
			allAnswers[36] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Fail: 37. conjunctionTest (/=) #2 : " << e.what() << endl;
	}

	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student studentArray1[] = {s1, s2, s3, s4};
		StudentSet set1(studentArray1, 4);
		StudentSet set3;
		StudentSet emptySet;
		set3 /= set1;
		if (set3 == emptySet && !(set3 != emptySet)) {
			cout << "Success: 38. conjunctionTest (/=) #3 " << emptySet << " /= " << set1  << endl;
			allAnswers[37] = 1;
		}
		else
			cout << "Fail: 38. conjunctionTest (/=) #3 " << emptySet << " /= " << set1  << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 38. conjunctionTest (/=) #3 : " << e.what() << endl;
	}

	try
	{
		StudentSet set3;
		StudentSet set4;
		set3 /= set4;
		if (set3 != set4 || !(set3 == set4))
			cout << "Fail: 39. conjunctionTest (/=) #4 " << set4 << " /= " << set4  << endl;
		else {
			cout << "Success: 39. conjunctionTest (/=) #4 " << set4 << " /= " << set4  << endl;
			allAnswers[38] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Fail: 39. conjunctionTest (/=) #3 : " << e.what() << endl;
	}
	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);
		Student s7(205, "Maeve", MANAGEMENT);
		Student studentArray1[] = {s1, s2, s3, s4};
		StudentSet set1(studentArray1, 4);
		Student studentArray3[] = {s5, s6, s7, s6};
		StudentSet set5(studentArray3, 4);
		Student answerArray[] = {s1, s2, s3, s4};
		StudentSet expected;
		StudentSet temp = set1;
		set1 /= set5;
		if (set1 == expected && !(set1 != expected)) {
			cout << "Success: 40. conjunctionTest (/=) #5 " << temp << " /= " << set5  << endl;
			allAnswers[39] = 1;
		}
		else
			cout << "Fail: 40. conjunctionTest (/=) #5 " << temp << " /= " << set5  << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 40. conjunctionTest (/=) #5 : " << e.what() << endl;
	}
	try
	{
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);
		Student s7(205, "Maeve", MANAGEMENT);
		StudentSet set3;
		Student studentArray3[] = {s5, s6, s7, s6};
		Student studentArray4[] = {s7, s5, s6, s6, s6};
		StudentSet set5(studentArray3, 4);
		StudentSet set6(studentArray4, 5);
		StudentSet temp = set6;
		set6 /= set5;
		StudentSet emptySet;
		if (set6 != set5 || !(set6 == set5))
			cout << "Fail: 41. conjunctionTest (/=) #6 " << temp << " /= " << set5  << endl;
		else {
			cout << "Success: 41. conjunctionTest (/=) #6 " << temp << " /= " << set5  << endl;
			allAnswers[40] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Success: 41. conjunctionTest (/=) #6 : " << e.what() << endl;
	}

	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);

		Student studentArray1[] = {s1, s2, s3, s4};
		Student studentArray2[] = {s3, s4, s5, s6};
		StudentSet set1(studentArray1, 4);
		StudentSet set2(studentArray2, 4);

		Student answerArray2[] = {s3};
		StudentSet expected2(answerArray2, 1);
		StudentSet answer = set1 / set2;
		if (answer == expected2 && !(answer != expected2)) {
			cout << "Success: 42. conjunctionTest (/) #1 " << set1 << " / " << set2  << endl;
			allAnswers[41] = 1;
		}
		else
			cout << "Fail: 42. conjunctionTest (/) #1 " << set1 << " / " << set2  << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 42. conjunctionTest (/) #1: " << e.what() << endl;
	}
	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student studentArray1[] = {s1, s2, s3, s4};
		StudentSet set1(studentArray1, 4);
		StudentSet set3;
		StudentSet answer = set1 / set3;
		if (answer != set3 || !(answer == set3))
			cout << "Fail: 43. conjunctionTest (/) #2 " << set1 << " / " << set3  << endl;
		else {
			cout << "Success: 43. conjunctionTest (/) #2 " << set1 << " / " << set3  << endl;
			allAnswers[42] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Fail: 43. conjunctionTest (/) #2 : " << e.what() << endl;
	}

	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student studentArray1[] = {s1, s2, s3, s4};
		StudentSet set1(studentArray1, 4);
		StudentSet set3;
		StudentSet answer = set3 / set1;
		if (answer == set3 && !(answer != set3)) {
			cout << "Success: 44. conjunctionTest (/) #3 " << set3 << " / " << set1  << endl;
			allAnswers[43] = 1;
		}
		else
			cout << "Fail: 44. conjunctionTest (/) #3 " << set3 << " / " << set1  << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 44. conjunctionTest (/) #3 : " << e.what() << endl;
	}

	try
	{
		StudentSet set3;
		StudentSet set4;
		StudentSet answer = set3 / set4;
		if (answer != set3 || !(answer == set3))
			cout << "Fail: 45. conjunctionTest (/) #4 " << set3 << " / " << set4  << endl;
		else {
			cout << "Success: 45. conjunctionTest (/) #4 " << set3 << " / " << set4  << endl;
			allAnswers[44] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Fail: 45. conjunctionTest (/) #4 : " << e.what() << endl;
	}
	try
	{
		Student s1(200, "Carmel", ENGINEERING);
		Student s2(201, "Ofer", HUMANITIES);
		Student s3(202, "Noam", MANAGEMENT);
		Student s4 = s3;
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);
		Student s7(205, "Maeve", MANAGEMENT);
		Student studentArray1[] = {s1, s2, s3, s4};
		StudentSet set1(studentArray1, 4);
		Student studentArray3[] = {s5, s6, s7, s6};
		StudentSet set5(studentArray3, 4);
		StudentSet answer = set1 / set5;
		StudentSet emptySet;
		if (answer == emptySet && !(answer != emptySet)) {
			cout << "Success: 46. conjunctionTest (/) #5 " << set1 << " / " << set5  << endl;
			allAnswers[22] = 1;
		}
		else
			cout << "Fail: 46. conjunctionTest (/) #5 " << set1 << " / " << set5  << endl;
	}
	catch (exception& e)
	{
		cout << "Fail: 46. conjunctionTest (/) #5 : " << e.what() << endl;
	}
	try
	{
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);
		Student s7(205, "Maeve", MANAGEMENT);
		Student studentArray3[] = {s5, s6, s7, s6};
		Student studentArray4[] = {s7, s5, s6, s6, s6};
		StudentSet set5(studentArray3, 4);
		StudentSet set6(studentArray4, 5);
		StudentSet answer = set6 / set5;
		if (answer != set5 || !(answer == set5))
			cout << "Fail: 47. onjunctionTest (/) #6 " << set6 << " / " << set5  << endl;
		else {
			cout << "Success: 47. onjunctionTest (/) #6 " << set6 << " / " << set5  << endl;
			allAnswers[46] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Fail: 47. onjunctionTest (/) #6 : " << e.what() << endl;
	}
	try
	{
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);
		Student s7(205, "Maeve", MANAGEMENT);
		Student studentArray3[] = {s5, s6, s7, s6};
		Student studentArray4[] = {s7, s5, s6, s6, s6};
		StudentSet set5(studentArray3, 4);
		StudentSet set6(studentArray4, 5);
		if (set5.getSize() != 3 || +set5 != 3)
			cout << "Fail: 48. unary operator (+) for size #1. Expected 3: Actual " << +set5 << endl;
		else {
			cout << "Success: 48. unary operator (+) for size #1" << endl;
			allAnswers[47] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Fail: 48. unary operator (+) for size #1 : " << e.what() << endl;
	}
	try
	{
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);
		Student s7(205, "Maeve", MANAGEMENT);
		Student studentArray3[] = {s5, s6, s7, s6};
		Student studentArray4[] = {s7, s5, s6, s6, s6};
		StudentSet set5(studentArray3, 4);
		StudentSet set6(studentArray4, 5);
		if (set6.getSize() != 3 || +set6 != 3)
			cout << "Fail: 49. unary operator (+) for size #2. Expected 3: Actual " << +set6 << endl;
		else {
			cout << "Success: 49. unary operator (+) for size #2" << endl;
			allAnswers[48] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Fail: 49. unary operator (+) for size #2 : " << e.what() << endl;
	}
	try
	{
		StudentSet set6;
		if (set6.getSize() != 0 || +set6 != 0)
			cout << "Fail: 50. unary operator (+) for size #3. Expected 0: Actual " << +set6 << endl;
		else {
			cout << "Success: 50. unary operator (+) for size #3" << endl;
			allAnswers[49] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Fail: 50. unary operator (+) for size #23 : " << e.what() << endl;
	}
	try
	{
		Student s5(203, "Dolores", MEDICINE);
		Student s6(204, "Bernard", GENERAL);
		Student s7(205, "Maeve", MANAGEMENT);
		Student studentArray3[] = {s5};
		StudentSet set5(studentArray3, 1);

		if (set5[0].getFaculty() != MEDICINE || set5[0].getID() != 203 || strcmp(set5[0].getName(), "Dolores") != 0)
			cout << "Fail: 51. Index operator ([]). Expected: " << s5 << " Actual: " << set5[0] << endl;
		else {
			cout << "Success: 51. Index operator ([])" << endl;
			allAnswers[50] = 1;
		}
	}
	catch (exception& e)
	{
		cout << "Fail: 51. Index operator ([]) : " << e.what() << endl;
	}
	return 0;
}
