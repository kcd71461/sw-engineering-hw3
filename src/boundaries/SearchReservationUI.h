//
// Created by 권영진 on 2018. 5. 28..
//

#ifndef SW_ENGINEERING_HW3_SEARCHRESERVATIONUI_H
#define SW_ENGINEERING_HW3_SEARCHRESERVATIONUI_H


#include "AbstractBoundary.h"

class SearchReservationControl;

/**
 * 예약 조회 기능 Boundary Class.
 */
class SearchReservationUI : public AbstractBoundary {
GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(SearchReservationControl)

public:
    void onSearchReservationRequest();
};


#endif //SW_ENGINEERING_HW3_SEARCHRESERVATIONUI_H
