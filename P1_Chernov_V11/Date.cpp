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
{
    // 
}

void Date::SetYear(const int year) {
    if (year < 0 || year > 2023) {
        throw std::runtime_error("Некорректное значение года");
    }
    this->year = year;
}

int Date::GetYear() const
{
    return year;
}

void Date::SetMonth(const int month) {
    if (month < 1 || month > 12) {
        throw std::runtime_error("Некорректное значение месяца");
    }
    this->month = month;
}

int Date::GetMonth() const
{
    return month;
}

void Date::SetDay(const int day) {
    if (day < 1 || day > 31) {
        throw std::runtime_error("Некорректное значение дня");
    }
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
    char point;
    if (!(stream >> year >> point >> month >> point >> day)) {
        throw std::runtime_error("Неверный формат даты");
    }

    if (point != '.') {
        throw std::runtime_error("Неверный разделитель даты. Используйте точку.");
    }

    this->SetYear(year);
    this->SetMonth(month);
    this->SetDay(day);
}

bool Date::ValidateDate(const std::string& date) {
    std::istringstream in(date);
    int year, month, day;
    char point;
    if (!(in >> year >> point >> month >> point >> day)) {
        throw std::runtime_error("Неверный формат даты");
        return false;
    }

    if (point != '.') {
        throw std::runtime_error("Неверный разделитель даты. Используйте точку.");
        return false;
    }

    if (month < 1 || month > 12 || day < 1 || day > 31 || year > 2023) {
        throw std::runtime_error("Некорректная дата");
        return false;
    }

    if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2 && day > 29)
    {
        throw std::runtime_error("date is visokosniy god, Feb day !>29");
        return false;
    }

    if (((year % 4 != 0 || year % 100 == 0) && year % 400 != 0) && month == 2 && day > 28)
    {
        throw std::runtime_error("date is ne visokosniy god, Feb day !>28");
        return false;
    }

    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
    {
        throw std::runtime_error("v month ne > 31 day");
        return false;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        throw std::runtime_error("v month ne > 30 day");
        return false;
    }
    return true;
}


void Date::InvalidDate(const std::string& date)
{
    if (date.empty() || !ValidateDate(date)) {
        throw std::runtime_error("Неправильное Время!");
    }
}