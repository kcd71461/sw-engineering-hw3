//
// Created by kimch on 2018-05-29.
//

#include "DateTimeUtils.h"

const char *DATE_STR_FORMAT = "%Y:%m:%d:%H:%M";

string DateTimeUtils::addDays(string time, int days) {
    struct tm tm = parseDateTimeString(time);
    tm.tm_mday += days;
    return getStringFromTime(mktime(&tm));
}

string DateTimeUtils::addYears(string time, int years) {
    struct tm tm = parseDateTimeString(time);
    tm.tm_year += years;
    return getStringFromTime(mktime(&tm));
}

tm DateTimeUtils::parseDateTimeString(string dateTime) {
    struct tm tm;
    strptime(dateTime.c_str(), DATE_STR_FORMAT, &tm);
    mktime(&tm);
    return tm;
}

string DateTimeUtils::getStringFromTime(time_t time) {
    char result[17];
    strftime(result, 20, DATE_STR_FORMAT, localtime(&time));
    return string(result);
}
