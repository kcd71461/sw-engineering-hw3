//
// Created by kimch on 2018-05-29.
//

#include "DateTimeUtils.h"

const char *DATE_STR_FORMAT = "%Y:%m:%d:%H:%M";

string DateTimeUtils::addDays(string time, int days) {
    struct tm tm = parseDateTimeString(time);
    tm.tm_mday += days;
    return getStringFromTime(&tm);
}

string DateTimeUtils::addYears(string time, int years) {
    struct tm tm = parseDateTimeString(time);
    tm.tm_year += years;
    return getStringFromTime(&tm);
}

tm DateTimeUtils::parseDateTimeString(string dateTime) {
    struct tm tm;
    strptime(dateTime.c_str(), DATE_STR_FORMAT, &tm);
    return tm;
}

string DateTimeUtils::getStringFromTime(tm *pTm) {
    char result[17];
    strftime(result, 20, DATE_STR_FORMAT, pTm);
    return string(result);
}
