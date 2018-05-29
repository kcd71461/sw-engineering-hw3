//
// Created by 권영진 on 2018. 5. 28..
//

#ifndef SW_ENGINEERING_HW3_OPAQUEINVENTORYUI_H
#define SW_ENGINEERING_HW3_OPAQUEINVENTORYUI_H


#include "AbstractBoundary.h"

class OpaqueInventoryControl;

class OpaqueInventoryUI : public AbstractBoundary {
GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(OpaqueInventoryControl)

public:
    void onOpaqueReservationRequest(string address, string date, int opaqueCost);
};


#endif //SW_ENGINEERING_HW3_OPAQUEINVENTORYUI_H
