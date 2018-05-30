//
// Created by 변상혁 on 2018-05-30.
//

#ifndef SW_ENGINEERING_HW3_HOSTACCOMMODATIONLISTUI_H
#define SW_ENGINEERING_HW3_HOSTACCOMMODATIONLISTUI_H

#include "AbstractBoundary.h"

class ListHostAccommodationControl;

/**
 * 호스트의 등록 숙소 리스트 기능 Boundary
 */
class ListHostAccommodationUI : public AbstractBoundary {
GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(ListHostAccommodationControl)

public:
    /**
     * 호스트가 등록숙소리스트를 요청 핸들러
     */
    void onListAccommodation();
};


#endif //SW_ENGINEERING_HW3_HOSTACCOMMODATIONLISTUI_H
