#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {

	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Colin,Roberson,roberson.colin@gmail.com,27,13,26,32,SOFTWARE" };

	cout << "CourseNum - Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 9999999" << endl;
	cout << "Name: Colin Roberson" << endl;

	//create classRoster object
	Roster classRoster;

	//loop through StudentData array and parse
	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]);
	}

	cout << endl << "Displaying all students:" << endl;

	classRoster.printAll();

	cout << endl << "Displaying invalid emails:" << endl << endl;

	classRoster.printInvalidEmails();

	cout << endl;

	//loop through classRoster array and print out Average Days in Course
	for (int i = 0; i < 5; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
	}

	cout << endl;

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	cout  << endl << "Removing A3:" << endl << endl;

	classRoster.remove("A3");

	classRoster.printAll();
	
	cout << endl << "Removing A3 again" << endl << endl;
	
	//this is expected to fail
	classRoster.remove("A3");

	cout << "DONE." << endl;

	return 0;
}