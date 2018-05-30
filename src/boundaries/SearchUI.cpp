//
// Created by simjae on 18. 5. 27.
//

#include "SearchUI.h"
#include "../controls/SearchControl.h"
#include <string>
GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(SearchUI,SearchControl)
using namespace std;

void SearchUI::listSearchResult(string address, string date) {
    this->getSearchControl()->searchAccommodations(address, date);
}

void SearchUI::onReservateButtonClick(string hostid, string guestid, string accommoname) {
    this->getSearchControl()->addReservation(hostid,guestid ,accommoname);
}