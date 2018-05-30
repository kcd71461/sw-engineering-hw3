//
// Created by simjae on 18. 5. 27.
//

#ifndef SW_ENGINEERING_HW3_SEARCHCONTROL_H
#define SW_ENGINEERING_HW3_SEARCHCONTROL_H


#include "../SingletonMacro.h"
#include "../boundaries/SearchUI.h"
#include "AbstractControl.h"
class SearchUI;

/**
 * 숙소 검색 + 예약 시도
 */
class SearchControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(SearchControl)
GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(SearchControl, SearchUI)

public:
    void searchAccommodations(string address, string date);

    void addReservation(string hostid,string guestid, string accommoname);
};

#endif //SW_ENGINEERING_HW3_SEARCHCONTROL_H
