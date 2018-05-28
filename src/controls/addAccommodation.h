#ifndef SW_ENGINEERING_HW3_addAccommodationCONTROL_H
#define SW_ENGINEERING_HW3_addAccommodationCONTROL_H

#include "../SingletonMacro.h"
#include "../boundaries/addAccommodationUI.h"
#include "AbstractControl.h"
class addAccommodationUI;

class addAccommodation : public AbstractControl {
GENERATE_SINGLETON_DECLARE(addAccommodation)
GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(addAccommodation, addAccommodationUI)

public:
    // TODO: 필요한 Control 함수 선언
    void addNewAccommodation(string hostid,string name, string address, int cost, string date, int opaqueCost);
};

#endif //SW_ENGINEERING_HW3_addAccommodationCONTROL_H