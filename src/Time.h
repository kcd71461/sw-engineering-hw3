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



#endif //SW_ENGINEERING_HW3_TIME_H
