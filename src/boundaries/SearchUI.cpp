//
// Created by simjae on 18. 5. 27.
//

#include "SearchUI.h"
#include "../controls/SearchControl.h"
#include <string>
GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(SearchUI,SearchControl)
using namespace std;

string SearchUI::listSearchResult(string address, string date) {
    return this->getSearchControl()->searchAccommodations(address, date);
}

string SearchUI::onReservateButtonClick(string hostid, string guestid, string accommoname) {
    return SearchControl::getInstance()->addReservation(hostid,guestid ,accommoname);
}

string SearchUI::getAllAccommodations() {


    return SearchControl::getInstance()->getAllAccommodations();


}

// TODO: 필요한 Boundary 함수 구현