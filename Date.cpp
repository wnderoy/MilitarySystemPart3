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

//----------------------------------------------------------------
// We should delete "isValid()" function because if the
// date wasn't valid then a Date object whould never be created.
//----------------------------------------------------------------

/* bool Date::isValid() const
{
    return (day >= 1) && (day <= 31) && (month >= 1) && (month <= 12) && (year >= 0);
} */


// --------------------------------------------------------------------
// (Monday 29/06/2026) - We're considering to remove this function
// in order to override operator<< function to enable larger support
// all across the system
// --------------------------------------------------------------------

/* void Date::print() const
{
    if (day < 10) {
        cout << "0";
    }
    cout << day << "/";
    if (month < 10) {
        cout << "0";
    }
    cout << month << "/" << year << endl;
} */
