#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <stdexcept>
#include <ctime>
#include <sstream>
#include <string>
#include <vector>

struct Day {
    Day(int day);

private:
    bool check_day(int) const;

public:
    int _day;
};

struct Month {
    Month(int month);

private:
    bool check_month(int) const;

public:
    int _month;
};

struct Year {
    Year(int year);

public:
    bool check_year(int) const;

public:
    int _year;
};

class Date {
public:
    Date();
    Date(const Year&, const Month&, const Day&);

    Day get_day() const;
    Month get_month() const;
    Year get_year() const;
    void set_day(Day day);
    void set_month(Month day);
    void set_year(Year day);
    bool is_valid() const;

private:
    Year m_year;
    Month m_month;
    Day m_day;
};

#endif //DATE_H