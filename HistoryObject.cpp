#include "HistoryObject.h"

HistoryObject::HistoryObject() {
    this->date_and_time = time(NULL);
    this->date_and_time_string = localtime(&date_and_time);
    this->hour = 0;
    this->minute = 0;
    this->second = 0;
    this->searched_string = "";
}

HistoryObject& HistoryObject::operator = (const HistoryObject& history_object) {
    this->hour = history_object.GetHour();
    this->minute = history_object.GetMinute();
    this->second = history_object.GetSecond();
    this->day = history_object.GetDay();
    this->month = history_object.GetMonth();
    this->year = history_object.GetYear();
    this->searched_string = history_object.searched_string;

    return *this;
}

void HistoryObject::SetSearchedString(std::string searched_string) {
    this->searched_string = searched_string;
}

void HistoryObject::SetDateAndTimeString() {
    this->date_and_time = time(NULL);
    this->date_and_time_string = localtime(&date_and_time);
    this->hour = this->date_and_time_string->tm_hour;
    this->minute = this->date_and_time_string->tm_min;
    this->second = this->date_and_time_string->tm_sec;
    this->day = this->date_and_time_string->tm_mday;
    this->month = this->date_and_time_string->tm_mon + 1;
    this->year = this->date_and_time_string->tm_year + 1900;
}

std::string HistoryObject::GetSearchedString() const {
    return this->searched_string;
}

int HistoryObject::GetHour() const {
    return this->hour;
}

int HistoryObject::GetMinute() const {
    return this->minute;
}

int HistoryObject::GetSecond() const {
    return this->second;
}

int HistoryObject::GetDay() const {
    return this->day;
}

int HistoryObject::GetMonth() const {
    return this->month;
}

int HistoryObject::GetYear() const {
    return this->year;
}