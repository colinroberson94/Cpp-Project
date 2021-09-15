#include <iostream>
#include <string>
#include "student.h"

using namespace std;



//Getters - Accessors
string Student::GetStudentID() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmail() const {
	return emailAddress;
}

int Student::GetAge() const {
	return age;
}

int Student::GetDaysToCompleteArray(int day) const{
	if (day < 3) {
		return numOfDaysInCourse[day];
	}
	else {
		return -999;
	}
}

string Student::GetDegreeProgram() {
	return degreeProgramStrings[int(degreeProgram)];
}

//Setters - Mutators
void Student::SetStudentID(string studentID) {
	this->studentID = studentID;
	return;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
	return;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;
	return;
}

void Student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
	return;
}

void Student::SetAge(int age) {
	this->age = age;
	return;
}

void Student::SetNumOfDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
	numOfDaysInCourse[0] = daysInCourse1;
	numOfDaysInCourse[1] = daysInCourse2;
	numOfDaysInCourse[2] = daysInCourse3;
	return;
}

void Student::SetDegreeProgram(string degree) {
	for (int i = 0; i < 3; ++i) {
		if (degreeProgramStrings[i] == degree) {
			degreeProgram = static_cast<DegreeProgram>(i);
		}
	}
	return;
}

void Student::print() {
	cout << studentID << "\t" << GetFirstName() << "\t" << GetLastName() << "\t" << GetAge() <<
		"\t{" << GetDaysToCompleteArray(0) << ", " << GetDaysToCompleteArray(1) << ", " <<
		GetDaysToCompleteArray(2) <<	"}\t" << GetDegreeProgram()	<< endl;

	return;
}

//Constructors
Student::Student() {
	SetStudentID("");
	SetFirstName("");
	SetLastName("");
	SetEmailAddress("");
	SetAge(-1);
	SetNumOfDaysInCourse(-1, -1, -1);
	SetDegreeProgram("NETWORK");
}
Student::Student(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string str_degreeProgram) {

	SetStudentID(studentID);
	SetFirstName(firstName);
	SetLastName(lastName);
	SetEmailAddress(emailAddress);
	SetAge(age);
	SetNumOfDaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);
	SetDegreeProgram(str_degreeProgram);
}

//Destructor
Student::~Student() {}