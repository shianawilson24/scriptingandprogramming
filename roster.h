#include <iostream>
#include "student.h"
#include <string>


class Roster
{
public:
    int Lastone;
    int MSize = 5;
    Student** classRosterArray; 

    
    Roster();
    Roster(int MSize);

    void parseThenAdd(string row);
    void add(
        string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram degreeprogam
    );

    Student* getStudent(int index);
    void printAll();
    bool remove(string studentID);
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeprogram);
    ~Roster();
};
