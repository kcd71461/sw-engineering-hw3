//
// Created by 권영진 on 2018. 5. 28..
//

#include "SearchReservationUI.h"
#include "../controls/SearchReservationControl.h"

GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(SearchReservationUI,SearchReservationControl)

void SearchReservationUI::onSearchReservationRequest(){
    this->getSearchReservationControl()->SearchReservation();
}
