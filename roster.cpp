#include <iostream>
#include "roster.h"
using namespace std;

Roster::Roster()
{
    this->MSize = 0;
    this->Lastone = -1;
    this->classRosterArray = nullptr;
}

Roster::Roster(int MSize)
{
    this->MSize = MSize;
    this->Lastone = -1;
    this->classRosterArray = new Student * [MSize];
}

void Roster::parseThenAdd(string row)
{
    int parseArr[Student::Real_tablesize];
    DegreeProgram degreeprogram;

    if (Lastone < MSize)
    {
        Lastone++;
    }

    this->classRosterArray[Lastone] = new Student();

    //Parse through the student data strong deliminated by comma
    //read student ID
    int long findit = row.find(",");
    classRosterArray[Lastone]->setID(row.substr(0, findit));
  
    //read firstName
    int long getit = findit + 1;
    findit = row.find(",", getit);
    classRosterArray[Lastone]->setFirst(row.substr(getit, findit - getit));

    //read lastName
    getit = findit + 1;
    findit = row.find(",", getit);
    classRosterArray[Lastone]->setLast(row.substr(getit, findit - getit));

    //read emailAddress
    getit = findit + 1;
    findit = row.find(",", getit);
    classRosterArray[Lastone]->setEmail(row.substr(getit, findit - getit));

    //read age
    getit = findit + 1;
    findit = row.find(",", getit);
    int x = stoi(row.substr(getit, findit - getit));
    classRosterArray[Lastone]->setAge(x);

    //read daysInCourse1
    getit = findit + 1;
    findit = row.find(",", getit);
    parseArr[0] = stoi(row.substr(getit, findit - getit));

   
    getit = findit + 1;
    findit = row.find(",", getit);
    parseArr[1] = stoi(row.substr(getit, findit - getit));

    
    getit = findit + 1;
    findit = row.find(",", getit);
    parseArr[2] = stoi(row.substr(getit, findit - getit));

    
    classRosterArray[Lastone]->setDaysToComplete(parseArr);

    
    getit = findit + 1;
    if (row[getit] == 'S')
    {
        if (row[getit + 1] == 'E') classRosterArray[Lastone]->setDegreeProgram(SECURITY);
        else if (row[getit + 1] == 'O') classRosterArray[Lastone]->setDegreeProgram(SOFTWARE);
        else
        {
            cerr << "This Degreee Program is not valid! Aborting request!" << endl;
            exit(-1);
        }
    }
    else if (row[getit] == 'N') classRosterArray[Lastone]->setDegreeProgram(NETWORK);
    else
    {
        cerr << "This Degreee Program is not valid! Aborting request!" << endl;
        exit(-1);
    }
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogam)
{
    int TheDaysTo_finish[Student::Real_tablesize];

    TheDaysTo_finish[0] = daysInCourse1;
    TheDaysTo_finish[1] = daysInCourse2;
    TheDaysTo_finish[2] = daysInCourse3;

    classRosterArray[Lastone] = new Student(studentID, firstName, lastName, emailAddress, age, TheDaysTo_finish, degreeprogam);
}

Student* Roster::getStudent(int index)
{
    return classRosterArray[index];
}

void Roster::printAll()
{
    for (int i = 0; i <= this->Lastone; i++) (this->classRosterArray)[i]->print();
}

bool Roster::remove(string ID)
{
    bool found = false;
    for (int i = 0; i <= Lastone; i++)
    {
        if (this->classRosterArray[i]->getStudentID() == ID)
        {
            found = true;
            delete this->classRosterArray[i];
            this->classRosterArray[i] = this->classRosterArray[Lastone];
            Lastone--;
        }
    }
    if (!found)
    {
        cout << "Student with ID " << ID << " not found." << endl;
    }
    return found;
}

void Roster::printAverageDaysInCourse(string sID)
{
    bool found = false;
    for (int i = 0; i <= Lastone; i++)
    {
        if (this->classRosterArray[i]->getStudentID() == sID)
        {
            found = true;
            int* ptr = classRosterArray[i]->getDaysToComplete();
            cout << "Average number of days left in class for " << sID << " is " << (ptr[0] + ptr[1] + ptr[2]) / 3 << "\n";
        }
    }
    if (!found) cout << "Student not found!\n";
}

void Roster::printInvalidEmails()
{
    cout << "Now listing invalid email addresses:\n";
    for (int i = 0; i < 5; i++)
    {
        string email = classRosterArray[i]->getEmailAddress();
        if ((email.find("@") == string::npos || email.find(".") == string::npos) || (email.find(" ") != string::npos))
            cout << email << endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
    cout << "Printing out students with degree program in " << DegreeProgramStrings[degreeprogram] << endl;
    for (int i = 0; i <= Lastone; i++) {
        if (this->classRosterArray[i]->getDegreeProgram() == degreeprogram) this->classRosterArray[i]->print();
    }
}

Roster::~Roster()
{
    for (int i = 0; i < 5; i++)
    {
        delete this->classRosterArray[i];
    }
    delete this;
}