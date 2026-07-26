#ifndef DATE_H
#define DATE_H
#include <ostream>

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    bool setDay(int day);
    bool setMonth(int month);
    bool setYear(int year);

    bool isValid() const;
    void print() const;

    friend std::ostream &operator<<(std::ostream &os, const Date &date)
    {
        if (date.day < 10)
        {
            os << "0";
        }
        os << date.day << "/";
        if (date.month < 10)
        {
            os << "0";
        }
        os << date.month << "/" << date.year;
        return os;
    }
};

#endif // DATE_H
