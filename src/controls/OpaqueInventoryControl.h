//
// Created by 권영진 on 2018. 5. 28..
//

#ifndef SW_ENGINEERING_HW3_OPAQUEINVENTORYCONTROL_H
#define SW_ENGINEERING_HW3_OPAQUEINVENTORYCONTROL_H


#include "../SingletonMacro.h"
#include "../boundaries/OpaqueInventoryUI.h"
#include "AbstractControl.h"

class OpaqueInventoryUI;

/**
 * OpaqueInventory 예약 시도 Control
 */
class OpaqueInventoryControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(OpaqueInventoryControl)

GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(OpaqueInventoryControl, OpaqueInventoryUI)

private:
    string addOpaqueReservation(string hostid, string accommodation, int opaqueCost);

public:
    /**
     * OpaqueInventory 예약을 시도
     * @param address
     * @param date
     * @param opaqueCost
     */
    void tryOpaqueInventoryReservation(string address, string date, int opaqueCost);
};


#endif //SW_ENGINEERING_HW3_OPAQUEINVENTORYCONTROL_H
