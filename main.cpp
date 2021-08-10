#include <iostream>
#include "roster.h"
using namespace std;




int main() {

    int numStudents = 5;

    const string studentData[5] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@mailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Shiana,Wilson,swi2112@wgu.edu,24,10,20,30,SOFTWARE",
    };

 

    Roster* ros = new Roster(numStudents);
    for (int i = 0; i < numStudents; i++)
    {
        ros->parseThenAdd(studentData[i]);
    }
   
    cout << "Shiana Wilson WGU ID:#001369775  Programming Language Used: C++" << endl;
    cout << "--Done--" << endl;

    cout << "Printing Full Roster: " <<endl;
    ros->printAll();
    cout << "--Done--" << endl;
    

    ros->printInvalidEmails();
    cout << "--Done--" << endl;

    cout << "The Average amount of days left to complete a course: " << endl;
    for (int i = 0; i < numStudents; i++) {
        ros->printAverageDaysInCourse(ros->getStudent(i)->getStudentID());
    }
    cout << "--Done--" << endl;

    ros->printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << "--Done--" << endl;

    cout << "Now removing student A3 from roster: " << endl;
    ros->remove("A3");
    cout << "--Done--" << endl;

    cout << "Printing full roster: " << endl;
    ros->printAll();
    cout << "--Done--" << endl;

    cout << "Removing student A3: " << endl;
    ros->remove("A3");
    cout << "--Done--" << endl;

    system("pause");

    return 0;
}


