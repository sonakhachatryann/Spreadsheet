#include "date.h"

Day::Day(int day) 
    : _day(1)
{
    if (check_day(day)) {
        _day = day;
    }
    else {
        throw std::invalid_argument("Invalid day.");
    }
}

bool Day::check_day(int day) const {
    if (day < 1 || day > 31) {
        return false;
    }
    return true;
}

Month::Month(int month) 
    : _month(1)
{
    if (check_month(month)) {
        _month = month;
    }
    else {
        throw std::invalid_argument("Invalid month.");
    }
}

bool Month::check_month(int month) const {
    if (month < 1 || month > 12) {
        return false;
    }
    return true;
}

Year::Year(int year) 
    : _year(1940)
{
    if (check_year(year)) {
        _year = year;
    }
    else {
        throw std::invalid_argument("Invalid year.");
    }
}

bool Year::check_year(int year) const {
    if (year < 1940 || year > 2030) {
        return false;
    }
    return true;
}

Date::Date(const Year& year, const Month& month, const Day& day) 
    : m_year(year)
    , m_month(month)
    , m_day(day)
{
    if (!is_valid()) {
        throw std::invalid_argument("Invalid date.");
    }
}

Day Date::get_day() const {
    return m_day;
}

Month Date::get_month() const {
    return m_month;
}

Year Date::get_year() const {
    return m_year;
}

void Date::set_day(Day day) {
    m_day = day;
}

void Date::set_month(Month month) {
    m_month = month;
}

void Date::set_year(Year year) {
    m_year = year;
}

bool Date::is_valid() const {
    if (m_month._month == 2) {
        if (m_year._year / 4) {
            if (m_day._day > 28) {
                return false;
            }
        
        }
        else if (m_day._day > 29) {
            return false;
        }
    }
    return true;
}