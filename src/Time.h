//
// Created by kimch on 5/27/2018.
//

#ifndef SW_ENGINEERING_HW3_TIME_H
#define SW_ENGINEERING_HW3_TIME_H

#include <string>

using namespace std;

class Time {
private:
    static string time;
public:
    static void setCurrentTime(string time);

    static string getCurrentTime();
};

string Time::time = "";

void Time::setCurrentTime(string time) {
    Time::time = time;
}

string Time::getCurrentTime() {
    return Time::time;
}


#endif //SW_ENGINEERING_HW3_TIME_H
