//
// Created by 심재철 on 18. 5. 29.
//
#include "Time.h"
#include "AccommodationCollection.h"
#include "DateTimeUtils.h"

string Time::_time = "";

void Time::setCurrentTime(string time) {
    Time::_time = time;
    AccommodationCollection *accommodations = AccommodationCollection::getInstance();
    for (int i = 0, length = accommodations->getSize(); i < length; i++) {
        Accommodation *accommodation = accommodations->get(i);
        string expireDate = DateTimeUtils::addYears(accommodation->getCreateDate(), 1); // 만료일: 등록일 + 1년

        // 만약 (만료일<현재시각 && 예약가능날짜+1일<현재시각) 이 참이면 숙소 삭제
        if (time.compare(expireDate) > 0 && time.compare(DateTimeUtils::addDays(accommodation->getDate(), 1))) {
            accommodations->remove(accommodation);
            i--;
            length--;
        }
    }
}

string Time::getCurrentTime() {
    return Time::_time;
}