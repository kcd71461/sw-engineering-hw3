//
// Created by 권영진 on 2018-05-29.
//

#ifndef SW_ENGINEERING_HW3_DATEUTILS_H
#define SW_ENGINEERING_HW3_DATEUTILS_H
#define NULL_TIME_STR ""
#include <string>

using namespace std;

/**
 * 시간 연산과 관련되 Util Class
 */
class DateTimeUtils {
private:
    /**
     * dateTime(string)을 파싱하여 tm 타입으로 반환
     * @param dateTime
     * @return
     */
    static tm parseDateTimeString(string dateTime);

    /**
     * tm* 타입을 date string으로 변환.
     * @param pTm
     * @return
     */
    static string getStringFromTime(tm* pTm);
public:
    /**
     * 입력받은 날짜에 입력받은 days를 더한 date string을 반환.
     * @param time
     * @param days
     * @return
     */
    static string addDays(string time, int days);

    /**
     * 입력받은 날짜에 입력받은 years를 더한 date string을 반환.
     * @param time
     * @param years
     * @return
     */
    static string addYears(string time, int years);
};


#endif //SW_ENGINEERING_HW3_DATEUTILS_H
