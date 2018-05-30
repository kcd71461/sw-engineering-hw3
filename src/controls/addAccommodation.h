#ifndef SW_ENGINEERING_HW3_addAccommodationCONTROL_H
#define SW_ENGINEERING_HW3_addAccommodationCONTROL_H

#include "../SingletonMacro.h"
#include "../boundaries/addAccommodationUI.h"
#include "AbstractControl.h"

class addAccommodationUI;

/**
 * 숙소 등록 기능 Control Class.
 */
class addAccommodation : public AbstractControl {
GENERATE_SINGLETON_DECLARE(addAccommodation)

GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(addAccommodation, addAccommodationUI)

public:
    /**
     * 새 Accommodation item 을 생성하여 AccommodationCollection에 추가한다.
     * @param hostid
     * @param name
     * @param address
     * @param cost
     * @param date
     * @param opaqueCost
     */
    void addNewAccommodation(string hostid, string name, string address, int cost, string date, int opaqueCost);
};

#endif //SW_ENGINEERING_HW3_addAccommodationCONTROL_H