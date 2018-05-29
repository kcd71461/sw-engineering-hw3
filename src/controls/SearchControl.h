//
// Created by simjae on 18. 5. 27.
//

#ifndef SW_ENGINEERING_HW3_SEARCHCONTROL_H
#define SW_ENGINEERING_HW3_SEARCHCONTROL_H


#include "../SingletonMacro.h"
#include "../boundaries/SearchUI.h"
#include "AbstractControl.h"
class SearchUI;

class SearchControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(SearchControl)
GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(SearchControl, SearchUI)

public:
    // TODO: 필요한 Control 함수 선언
    string searchAccommodations(string address, string date);
    string addReservation(string hostid,string guestid, string accommoname);
    string getAllAccommodations();
};

#endif //SW_ENGINEERING_HW3_SEARCHCONTROL_H
