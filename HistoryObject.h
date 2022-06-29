#pragma once
#include "Address.h"
#include "Contact.h"
#include "ContactsGroup.h"

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB

class HistoryObject{
    time_t date_and_time;
    tm* date_and_time_string;
    std::string searched_string;
    int hour, minute, second;
    int day, month, year;
public:

    HistoryObject();
    HistoryObject& operator = (const HistoryObject& history_object);
    void SetSearchedString(std::string searched_string);
    void SetDateAndTimeString();
    std::string GetSearchedString() const;
    int GetHour() const;
    int GetMinute() const;
    int GetSecond() const;
    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;
};

