#pragma once
#include "degree.h"
#include <string>
#include <iostream>
using namespace std;


class Student
{
public:
    const static int Real_tablesize = 3;

private:  
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int* TheDaysTo_finish;
    DegreeProgram studentsdegreeprog;

public:
    
    Student();

    
    Student(
        string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        int TheDaysTo_finish[],
        DegreeProgram studentsdegreeprog
    );

    
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysToComplete();
    DegreeProgram getDegreeProgram();

    
    void setID(string studentID);
    void setFirst(string firstName);
    void setLast(string lastName);
    void setEmail(string emailAddress);
    void setAge(int age);
    void setDaysToComplete(int TheDaysTo_finish[]);
    void setDegreeProgram(DegreeProgram studentsdegreeprog);
    void print();

    
    ~Student();

};