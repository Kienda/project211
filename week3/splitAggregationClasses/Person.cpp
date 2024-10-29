#include "Person.h"

Person::Person()
{
    fname = "Abdoulaye";
    mi = "Alhassane";
    lastname = "Diallo";
}

Person::Person(string f, string m, string l)
{
    fname = f;
    mi = m;
    lastname = l;
}

Person::~Person() {}

string Person::getFName() { return fname; }
string Person::getMiddle() { return mi; }
string Person::getLastName() { return lastname; }

void Person::setLName(string l) { lastname = l; }
void Person::setFname(string f) { fname = f; }
void Person::setMiddle(string m) { mi = m; }
