//
// Created by 권영진 on 2018-05-28.
//

#ifndef SW_ENGINEERING_HW3_TIME_H
#define SW_ENGINEERING_HW3_TIME_H


#include <string>

using namespace std;

/**
 * 현재 시각 관련 Util Class
 */
class Time {
private:
    static string _time; // 현재 시각
public:

    /**
     * 현재 시각 설정
     * @param time
     */
    static void setCurrentTime(string time);

    /**
     * 현재 시각 getter
     * @return
     */
    static string getCurrentTime();
};

#endif //SW_ENGINEERING_HW3_TIME_H
