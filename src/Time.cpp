//
// Created by simjae on 18. 5. 29.
//
#include "Time.h"

string Time::time = "";

void Time::setCurrentTime(string time) {
    Time::time = time;
}

string Time::getCurrentTime() {
    return Time::time;
}
