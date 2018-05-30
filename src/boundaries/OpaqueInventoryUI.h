//
// Created by 권영진 on 2018. 5. 28..
//

#ifndef SW_ENGINEERING_HW3_OPAQUEINVENTORYUI_H
#define SW_ENGINEERING_HW3_OPAQUEINVENTORYUI_H


#include "AbstractBoundary.h"

class OpaqueInventoryControl;

/**
 * Opque 예약 시도 기능 Boundary Class.
 */
class OpaqueInventoryUI : public AbstractBoundary {
GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(OpaqueInventoryControl)

public:
    /**
     * Opaque 예약 요청
     * @param address
     * @param date
     * @param opaqueCost
     */
    void onOpaqueReservationRequest(string address, string date, int opaqueCost);
};


#endif //SW_ENGINEERING_HW3_OPAQUEINVENTORYUI_H
