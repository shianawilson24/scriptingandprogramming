#include <iostream>
#include "student.h"
#include <string>

using namespace std;


Student::Student() 
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->TheDaysTo_finish = new int[Real_tablesize];
    for (int i = 0; i < Real_tablesize; i++) this->TheDaysTo_finish[i] = 0;
    this->studentsdegreeprog = SOFTWARE;

}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int TheDaysTo_finish[], DegreeProgram studentsdegreeprog)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->TheDaysTo_finish = new int[Real_tablesize];
    for (int i = 0; i < Real_tablesize; i++) this->TheDaysTo_finish[i] = TheDaysTo_finish[i];
    this->studentsdegreeprog  = studentsdegreeprog;
}

//Accessor functions
string Student::getStudentID()
{
    return studentID;
}

string Student::getFirstName()
{
    return firstName;
}

string Student::getLastName()
{
    return lastName;
}

string Student::getEmailAddress()
{
    return emailAddress;
}

int Student::getAge()
{
    return age;
}

int* Student::getDaysToComplete()
{
    return TheDaysTo_finish;           //pointer to an array
}

DegreeProgram Student::getDegreeProgram()
{
    return studentsdegreeprog;
}


//Mutator functions

void Student::setID(string studentID)
{
    this->studentID = studentID;
}

void Student::setFirst(string firstName)
{
    this->firstName = firstName;
}

void Student::setLast(string lastName)
{
    this->lastName = lastName;
}

void Student::setEmail(string emailAddress)
{
    this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
    this->age = age;
}

void Student::setDaysToComplete(int TheDaysTo_finish[])
{
    for (int i = 0; i < Real_tablesize; i++)
    {
        this->TheDaysTo_finish[i] = TheDaysTo_finish[i];
    }
}

void Student::setDegreeProgram(DegreeProgram studentsdegreeprog)
{
    this->studentsdegreeprog = studentsdegreeprog;
}

void Student::print()
{
    cout << getStudentID() << '\t' << getFirstName() << '\t' << getLastName() << '\t' << getAge() << '\t';
    int* TheDaysTo_finish = getDaysToComplete();
    cout << '\t' << "daysInCourse: " << "{" << TheDaysTo_finish[0] << ", " << TheDaysTo_finish[1] << ", " << TheDaysTo_finish[2] << "}" << '\t';
    cout << "Degree Program: " << DegreeProgramStrings[getDegreeProgram()] << endl;
}

//Destructor
Student::~Student()
{
    if (TheDaysTo_finish != nullptr)
    {
        delete[] TheDaysTo_finish;
        TheDaysTo_finish = nullptr;
    }
}