//
// Created by 권영진 on 2018. 5. 28..
//
#include "OpaqueInventoryUI.h"
#include "../controls/OpaqueInventoryControl.h"

GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(OpaqueInventoryUI,OpaqueInventoryControl)

void OpaqueInventoryUI::onOpaqueReservationRequest(string address, string date, int opaqueCost) {
    this->getOpaqueInventoryControl()->tryOpaqueInventoryReservation(address, date, opaqueCost);
}