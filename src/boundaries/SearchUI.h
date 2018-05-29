//
// Created by simjae on 18. 5. 27.
//

#ifndef SW_ENGINEERING_HW3_SEARCHUI_H
#define SW_ENGINEERING_HW3_SEARCHUI_H


#include "AbstractBoundary.h"

class SearchControl;

class SearchUI : public AbstractBoundary {
GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(SearchControl)

public:
    // TODO: 필요한 Boundary 함수 선언
    string listSearchResult(string basic_string, string basicString);
    string onReservateButtonClick(string hostid,string guestid,string accommoname);
    string getAllAccommodations();
};

#endif //SW_ENGINEERING_HW3_SEARCHUI_H
