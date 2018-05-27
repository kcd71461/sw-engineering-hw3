//
// Created by simjae on 18. 5. 27.
//

#include "addAccommodationUI.h"
#include "../controls/addAccommodationControl.h"

GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(addAccommodationUI,addAccommodationControl)

void addAccommodationUI::onaddAccommodation(string address, string date) {
    this->getaddAccommodationControl()->addAccommodation(address, date);
}
// TODO: 필요한 Boundary 함수 구현