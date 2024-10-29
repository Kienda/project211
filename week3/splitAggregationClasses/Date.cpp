#include "Date.h"

Date::Date()
{
    month = "January";
    year = 2024;
    day = 10;
}

Date::Date(string m, int y, int d)
{
    month = m;
    year = y;
    day = d;
}

Date::~Date() {}

string Date::getMonth() { return month; }
int Date::getYear() { return year; }
int Date::getDay() { return day; }

void Date::setMonth(string m) { month = m; }
void Date::setYear(int y) { year = y; }
void Date::setDay(int d) { day = d; }
