//
// Created by 권영진 on 2018. 5. 28..
//
#include "OpaqueInventoryUI.h"
#include "../controls/OpaqueInventoryControl.h"

GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(OpaqueInventoryUI,OpaqueInventoryControl)

string OpaqueInventoryUI::onOpaqueReservationRequest(string address, string date, int opaqueCost) {
    return this->getOpaqueInventoryControl()->tryOpaqueInventoryReservation(address, date, opaqueCost);
}
// TODO: 필요한 Boundary 함수 구현