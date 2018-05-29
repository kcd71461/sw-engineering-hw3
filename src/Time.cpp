//
// Created by simjae on 18. 5. 29.
//
#include "Time.h"

string Time::_time = "";

void Time::setCurrentTime(string time) {
    Time::_time = time;
}

string Time::getCurrentTime() {
    return Time::_time;
}