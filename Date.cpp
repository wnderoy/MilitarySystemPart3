#include <iostream>
#include "Date.h"
using namespace std;

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

bool Date::setDay(int day)
{
    if (day >= 1 && day <= 31) {
        this->day = day;
        return true;
    }
    return false;
}

bool Date::setMonth(int month)
{
    if (month >= 1 && month <= 12) {
        this->month = month;
        return true;
    }
    return false;
}

bool Date::setYear(int year)
{
    if (year >= 0) {
        this->year = year;
        return true;
    }
    return false;
}
