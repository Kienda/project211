#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() {}

Student::Student(Person pName, Date dBirthday, string maj, Date dGrad, int idN, double gpaN, string ssn)
{
    major = maj;
    id = idN;
    gpa = gpaN;
    ssno = ssn;
    name = pName;
    birthday = dBirthday;
    dateOfGraduation = dGrad;
}

Student::~Student() {}

string Student::getLastName() { return name.getLastName(); }
string Student::getFName() { return name.getFName(); }
string Student::getMiddle() { return name.getMiddle(); }

void Student::setLastName(string m) { name.setLName(m); }
void Student::setMajor(string maj) { major = maj; }
void Student::setId(int idN) { id = idN; }
void Student::setGpa(double gpaN) { gpa = gpaN; }
void Student::setSsn(string ssn) { ssno = ssn; }

string Student::getMajor() { return major; }
int Student::getId() { return id; }
double Student::getGpa() { return gpa; }
string Student::getSsn() { return ssno; }

void Student::printStudentInfo()
{
    cout << "Student Information: " << endl;
    cout << "Name: " << name.getFName() << " " << name.getMiddle() << " " << name.getLastName() << endl;
    cout << "Birthday: " << birthday.getMonth() << " " << birthday.getDay() << ", " << birthday.getYear() << endl;
    cout << "Major: " << major << endl;
    cout << "ID: " << id << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Social Security Number: " << ssno << endl;
    cout << "Date of Graduation: " << dateOfGraduation.getMonth() << " " << dateOfGraduation.getDay() << ", " << dateOfGraduation.getYear() << endl;
}
