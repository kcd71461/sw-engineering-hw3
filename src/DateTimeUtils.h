//
// Created by kimch on 2018-05-29.
//

#ifndef SW_ENGINEERING_HW3_DATEUTILS_H
#define SW_ENGINEERING_HW3_DATEUTILS_H

#include <string>

using namespace std;

class DateTimeUtils {
private:
    static tm parseDateTimeString(string dateTime);
    static string getStringFromTime(time_t time);
public:
    static string addDays(string time, int days);

    static string addYears(string time, int years);
};


#endif //SW_ENGINEERING_HW3_DATEUTILS_H