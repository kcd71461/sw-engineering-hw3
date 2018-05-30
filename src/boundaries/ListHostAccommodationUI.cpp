//
// Created by 김창덕 on 2018-05-30.
//

#include "ListHostAccommodationUI.h"
#include "../controls/ListHostAccommodationControl.h"

GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(ListHostAccommodationUI,ListHostAccommodationControl)

void ListHostAccommodationUI::onListAccommodation() {
    this->getListHostAccommodationControl()->listAccommodations();
}
