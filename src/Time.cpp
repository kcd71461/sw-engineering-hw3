//
// Created by kimch on 2018-05-28.
//

#include "Time.h"

string Time::_time = "";

void Time::setCurrentTime(string time) {
    _time = time;
}

string Time::getCurrentTime() {
    return _time;
}
