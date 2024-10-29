#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Date.h"
#include <string>
using namespace std;

class Student
{
private:
    Person name;
    Date birthday;
    string major;
    int id;
    Date dateOfGraduation;
    double gpa;
    string ssno;

public:
    Student();
    Student(Person pName, Date dBirthday, string maj, Date dGrad, int idN, double gpaN, string ssn);
    ~Student();

    string getLastName();
    string getFName();
    string getMiddle();
    void setLastName(string m);
    void setMajor(string maj);
    void setId(int idN);
    void setGpa(double gpaN);
    void setSsn(string ssn);
    string getMajor();
    int getId();
    double getGpa();
    string getSsn();
    void printStudentInfo();
};

#endif
