#pragma once

#include <iostream>

struct Date {

    int day;
    int month;
    int year;

    Date(int day, int month, int year);
    Date();

    void SetYear(const int year);
    int GetYear() const;

    void SetMonth(const int month);
    int GetMonth() const;

    void SetDay(const int day);
    int GetDay() const;

    void print(std::ostream& out = std::cout) const;
    void create_from_stream(std::istream& stream);

    static bool ValidateDate(const std::string& date);
    static void InvalidDate(const std::string& date);


};