#pragma once

#include "Date.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Date::Date()
    : day(0)
    , month(0)
    , year(0)
{}

Date::Date(int day, int month, int year)
    : day(day)
    , month(month)
    , year(year)
{}

void Date::SetYear(const int year)
{
    this->year = year;
}

int Date::GetYear() const
{
    return year;
}

void Date::SetMonth(const int month)
{
    this->month = month;
}

int Date::GetMonth() const
{
    return month;
}

void Date::SetDay(const int day)
{
    this->day = day;
}

int Date::GetDay() const
{
    return day;
}

void Date::print(std::ostream& out) const {
    const char point = '.';
    out << "Дата выдачи: "
        << this->GetYear() << point
        << std::setfill('0') << std::setw(2) << this->GetMonth() << point
        << std::setfill('0') << std::setw(2) << this->GetDay() << std::endl;
}

void Date::create_from_stream(std::istream& stream) {
    int year, month, day;
    char point = '.';
    if (stream >> year >> point >> month >> point >> day)
    {
        this->SetYear(year);
        this->SetMonth(month);
        this->SetDay(day);
    }
}
bool Date::ValidateDate(const std::string& date) {
    std::istringstream in(date);
    int year, month, day;
    char point = '.';
    in >> year >> point >> month >> point >> day;
    if (in.fail() || year < 2000 || year > 9999 || month > 12 || month < 1 || day > 31 || day < 1) {
        return false;
    }
    return true;
}

void Date::InvalidDate(const std::string& date)
{
    if (date.empty() || !ValidateDate(date)) {
        throw std::runtime_error("Неправильное Время!");
    }
    ValidateDate(date);
}