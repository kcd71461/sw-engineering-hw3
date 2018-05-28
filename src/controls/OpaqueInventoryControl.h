//
// Created by 권영진 on 2018. 5. 28..
//

#ifndef SW_ENGINEERING_HW3_OPAQUEINVENTORYCONTROL_H
#define SW_ENGINEERING_HW3_OPAQUEINVENTORYCONTROL_H


#include "../SingletonMacro.h"
#include "../boundaries/OpaqueInventoryUI.h"
#include "AbstractControl.h"
class OpaqueInventoryUI;

class OpaqueInventoryControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(OpaqueInventoryControl)
GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(OpaqueInventoryControl, OpaqueInventoryUI)

public:
    // TODO: 필요한 Control 함수 선언
    void tryOpaqueInventoryReservation(string address, string date, int opaqueCost);
    string addOpaqueReservation(string hostid, string accommodation);
};


#endif //SW_ENGINEERING_HW3_OPAQUEINVENTORYCONTROL_H
