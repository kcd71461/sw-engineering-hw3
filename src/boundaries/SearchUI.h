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
    void listSearchResult(string basic_string, string basicString);
    void onReservateButtonClick(string hostid,string guestid,string accommoname);
    /**
     * 등록한 숙소 조회
     */
    void getAllAccommodations();
};

#endif //SW_ENGINEERING_HW3_SEARCHUI_H
