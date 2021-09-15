#pragma once
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

class Student {
public:
	//Constructor
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, 
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string str_degreeProgram);

	//Destructor
	~Student();

	//Getters - Accessors
	string GetStudentID() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmail() const;
	int GetAge() const;
	int GetDaysToCompleteArray(int day) const;
	string GetDegreeProgram();

	//Setters - Mutators
	void SetStudentID(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmailAddress(string emailAddress);
	void SetAge(int age);
	void SetNumOfDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
	void SetDegreeProgram(string degree);

	void print();

private:
	string studentID;
	string firstName; 
	string lastName;
	string emailAddress;
	int age;
	int numOfDaysInCourse[3];
	DegreeProgram degreeProgram;
	string str_degreeProgram;
};
