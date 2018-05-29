//
// Created by kimch on 2018-05-28.
//

#ifndef SW_ENGINEERING_HW3_TIME_H
#define SW_ENGINEERING_HW3_TIME_H


#include <string>

using namespace std;

class Time {
private:
    static string _time;
public:
    static void setCurrentTime(string time);

    static string getCurrentTime();
};

#endif //SW_ENGINEERING_HW3_TIME_H
