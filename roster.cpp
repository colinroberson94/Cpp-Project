#include <iostream>
#include <string>
#include "roster.h"

using namespace std;
/*
 - This function will create a new Student object and add to the classRoster Array
 - the function loops through the classRosterArray in search of the first "empty"
   element. Once that is found, it "places" the student object in this location
   and breaks out of the loop.
*/
void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string str_degreeProgram) {
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] == nullptr) {
			Student* tempStudent =
				new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, str_degreeProgram);
			
			classRosterArray[i] = { tempStudent };
			break;
		}
	}
	return;
}


/*
 - This function takes a long string and breaks it up using a comma as the delimiter
 - ALL text between two commas (or the begining of the string and the first comma)
   will be assigned to a variable and then passed to the "add" function above
 - Input must follow the format:
   "Student_ID,F_Name,L_Name,Email,Age,DayInCourse1,DayInCourse2,DayInCourse1,Degree_Type"
*/
void Roster::parse(string studentData) {

		size_t rhs = studentData.find(",");
		string studentID = studentData.substr(0, rhs);

		size_t lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string firstName = studentData.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string lastName = studentData.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string emailAddress = studentData.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int age = stoi(studentData.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string str_degreeProgram = studentData.substr(lhs, rhs - lhs);

		Roster::add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, str_degreeProgram);

	return;
}

/*
 - function takes a Student ID as input
 - loops through classRosterArray searching for an object with a matching Student ID
 - While searching, the function will skip over nullptr's (i.e. deleted entries)
 - If a match is found, that object is erased and the bool is set to TRUE
 - Once a match is found or all objects have been checked, the function exits.
*/
void Roster::remove(string studentID) {
	bool found = false;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] == nullptr) {
			break;
		}
		else if (classRosterArray[i]->GetStudentID() == studentID) {
			classRosterArray[i] = nullptr;
			found = true;
			break;
		}
	}

	if (found == false) {
		cout << "The student with ID: " << studentID << " was not found." << endl;
	}

}

/*
 - Function loops through classRosterArray and print's out all valid elements
*/
void Roster::printAll() {
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] == nullptr) {
			continue;
		}
		else {
			classRosterArray[i]->print();
		}
	}
	return;
}

/*
 - Function takes a studentID as input
 - loops through classRosterArray in search of an Object with a matching Student ID
 - Once that object is found it computes and displays the average time taken to complete 
   the provide courses
*/
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			int averageDaysInCourse = 0;
			int sum = 0;
			for (int j = 0; j < 3; j++) {
				sum += classRosterArray[i]->GetDaysToCompleteArray(j);
			}
			averageDaysInCourse = sum / 3;
			cout << "Student ID: " << classRosterArray[i]->GetStudentID() <<
				", average days in course is: " << averageDaysInCourse << endl;
			break;
		}
	}
}

/*
 - Function loops through all objects/elements in classRosterArray and displays invalid emails
 - Determines validity by ensuring all provided addresses contain an '@', '.', and no spaces
*/
void Roster::printInvalidEmails() {


	for (int i = 0; i < 5; i++) {
		string tempStr = classRosterArray[i]->GetEmail();
		if ((tempStr.find(' ') != string::npos) ||
			(tempStr.find('@') == string::npos) ||
			(tempStr.find('.') == string::npos)) {
			cout << classRosterArray[i]->GetEmail() << " - is invalid." << endl;
		}
	}
}

/*
 - Function takes a DegreeProgram enum value
 - searches through classRosterArray in search of objects with matching DegreeProgram
 - prints out student's with matching degreeProgram
*/
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Showing students in degree program: " << degreeProgramStrings[int(degreeProgram)] << endl << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgramStrings[int(degreeProgram)]) {
			classRosterArray[i]->print();
		}
	}
}


//Constructor
Roster::Roster() {
	classRosterArray[0] = { nullptr };
	classRosterArray[1] = { nullptr };
	classRosterArray[2] = { nullptr };
	classRosterArray[3] = { nullptr };
	classRosterArray[4] = { nullptr };
	return;
}

//Destructor
Roster::~Roster() {
	delete classRosterArray[0];
	delete classRosterArray[1];
	delete classRosterArray[2];
	delete classRosterArray[3];
	delete classRosterArray[4];
	return;
}