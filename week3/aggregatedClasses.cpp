#include <iostream>
using namespace std;
#include <string>
/*
Task 1: make all member variables private
Task 2: create getter and setter for all member variables in all three classes
Task 3: add a printStudentInfo inside Student class
Task 4: Create Student object, Initialize the member variables and call printStudentInfo in the main
Task 5: Add constructors for all classes
Task 6: Add destructors for all classes
Task 7: Separate classes in .h and .cpp
*/

class Person
{
private:
    string fname, mi;
    string lastname;

public: // should be private
    Person()
    {
        fname = "Abdoulaye";
        mi = "Alhassane";
        lastname = "Diallo";
    }

    Person(string f, string m, string l)
    {
        fname = f;
        mi = m;
        lastname = l;
    }

    ~Person()
    {
    }

    string getFName() { return fname; }
    string getMiddle() { return mi; }
    string getLastName() { return lastname; }

    void setLName(string l) { lastname = l; }
    void setFname(string f) { fname = f; }
    void setMiddle(string m) { mi = m; }
};

class Date
{
private:
    string month;
    int year, day;

public:
    Date()
    {
        month = "January";
        year = 2024;
        day = 10;
    };

    Date(string m, int y, int d)
    {
        month = m;
        year = y;
        day = d;
    }

    ~Date()
    {
    }

    string getMonth() { return month; }
    int getYear() { return year; }
    int getDay() { return day; }

    void setMonth(string m) { month = m; }
    void setYear(int y) { year = y; }
    void setDay(int d) { day = d; }
};

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
    Student() {}

    Student(Person pName, Date dBirthday, string maj, Date dGrad, int idN, double gpaN, string ssn)
    {
        major = maj;
        id = idN;
        gpa = gpaN;
        ssno = ssn;
        name = pName;
        birthday = dBirthday;
        dateOfGraduation = dGrad;
    }

    string getLastName() { return name.getLastName(); }
    string getFName() { return name.getFName(); }
    string getMiddle() { return name.getMiddle(); }

    // Setter methods for student's personal information
    void setLastName(string m) { name.setLName(m); }

    void setMajor(string maj) { major = maj; }
    void setId(int idN) { id = idN; }
    void setGpa(double gpaN) { gpa = gpaN; }
    void setSsn(string ssn) { ssno = ssn; }

    string getMajor() { return major; }
    int getId() { return id; }
    double getGpa() { return gpa; }
    string getSsn() { return ssno; }

    void printStudentInfo()
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
};

int main()
{
    Person person("Abdoulaye", "M.", "Doe");
    Date birthday("March", 2000, 15);
    Date graduationDate("May", 2025, 20);

    Student student(person, birthday, "Computer Science", graduationDate, 123456, 3.9, "123-45-6789");
    student.printStudentInfo();

    return 0;
}