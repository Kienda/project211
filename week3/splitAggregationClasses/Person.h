#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
private:
    string fname, mi, lastname;

public:
    Person();
    Person(string f, string m, string l);
    ~Person();

    string getFName();
    string getMiddle();
    string getLastName();
    void setLName(string l);
    void setFname(string f);
    void setMiddle(string m);
};

#endif
