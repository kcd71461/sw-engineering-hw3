//
// Created by 김창덕 on 2018-05-30.
//

#ifndef SW_ENGINEERING_HW3_HOSTACCOMMODATIONLISTCONTROL_H
#define SW_ENGINEERING_HW3_HOSTACCOMMODATIONLISTCONTROL_H


#include "../SingletonMacro.h"
#include "../boundaries/ListHostAccommodationUI.h"
#include "AbstractControl.h"

class ListHostAccommodationUI;

/**
 * 등록 숙소 list 기능 Control Class.
 */
class ListHostAccommodationControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(ListHostAccommodationControl)

GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(ListHostAccommodationControl, ListHostAccommodationUI)

public:
    /**
     * 현재 세션이 호스트이면 등록 숙소를 list
     */
    void listAccommodations();
};


#endif //SW_ENGINEERING_HW3_HOSTACCOMMODATIONLISTCONTROL_H
