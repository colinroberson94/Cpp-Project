#pragma once
#include <iostream>
#include <string>

using namespace std;

enum class DegreeProgram { SECURITY, NETWORK, SOFTWARE };
const string degreeProgramStrings[3] = { "SECURITY", "NETWORK", "SOFTWARE" };

/*

****Quick little demonstration/example program*****

enum class DegreeProgram { SECURITY, NETWORK, SOFTWARE };
string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };

int main() {

    DegreeProgram colinRoberson = DegreeProgram::SOFTWARE;

    //Will return "software"
    cout << "You're degree is: " << degreeProgramStrings[int(colinRoberson)] << endl;

    //Will return 2
    cout << int(colinRoberson);

    return 0;
}

*/