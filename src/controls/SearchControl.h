//
// Created by 변상혁 on 18. 5. 27.
//

#ifndef SW_ENGINEERING_HW3_SEARCHCONTROL_H
#define SW_ENGINEERING_HW3_SEARCHCONTROL_H


#include "../SingletonMacro.h"
#include "../boundaries/SearchUI.h"
#include "AbstractControl.h"
class SearchUI;

/**
 * 숙소 검색 + 예약 시도 기능 Control Class.
 */
class SearchControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(SearchControl)
GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(SearchControl, SearchUI)

public:
    /**
     * 입력받은 조건을 만족하는 숙소를 list
     * @param address
     * @param date
     */
    void searchAccommodations(string address, string date);

    /**
     * Reservation Item을 생성하여 ReservationCollection에 추가
     * @param hostid
     * @param guestid
     * @param accommoname
     */
    void addReservation(string hostid,string guestid, string accommoname);
};

#endif //SW_ENGINEERING_HW3_SEARCHCONTROL_H
