//
// Created by 권영진 on 2018. 5. 28..
//

#ifndef SW_ENGINEERING_HW3_SEARCHRESERVATIONCONTROL_H
#define SW_ENGINEERING_HW3_SEARCHRESERVATIONCONTROL_H

#include "../SingletonMacro.h"
#include "../boundaries/SearchReservationUI.h"
#include "AbstractControl.h"
class SearchReservationUI;

/**
 * 예약 내역 조회
 */
class SearchReservationControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(SearchReservationControl)
GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(SearchReservationControl, SearchReservationUI)

public:
    /**
     * 현재 세션의 예약 내역을 list
     */
    void SearchReservation();
};


#endif //SW_ENGINEERING_HW3_SEARCHRESERVATIONCONTROL_H
