//
// Created by simjae on 18. 5. 27.
//

#ifndef SW_ENGINEERING_HW3_SEARCHUI_H
#define SW_ENGINEERING_HW3_SEARCHUI_H


#include "AbstractBoundary.h"

class SearchControl;

/**
 * 숙소 검색+예약기능 Boundary Class.
 */
class SearchUI : public AbstractBoundary {
GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(SearchControl)

public:
    /**
     * 검색 요청
     * @param basic_string
     * @param basicString
     */
    void listSearchResult(string basic_string, string basicString);

    /**
     * 예약 시도
     * @param hostid
     * @param guestid
     * @param accommoname
     */
    void onReservateButtonClick(string hostid,string guestid,string accommoname);
};

#endif //SW_ENGINEERING_HW3_SEARCHUI_H
