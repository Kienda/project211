#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date
{
private:
    string month;
    int year, day;

public:
    Date();
    Date(string m, int y, int d);
    ~Date();

    string getMonth();
    int getYear();
    int getDay();
    void setMonth(string m);
    void setYear(int y);
    void setDay(int d);
};

#endif
