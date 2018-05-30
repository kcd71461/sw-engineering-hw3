//
// Created by 심재철 on 18. 5. 27.
//

#ifndef SW_ENGINEERING_HW3_ADDACCOMMODATIONUI_H
#define SW_ENGINEERING_HW3_ADDACCOMMODATIONUI_H


#include "AbstractBoundary.h"

class addAccommodationControl;

/**
 * 숙소 등록 기능 Boundary Class.
 */
class addAccommodationUI : public AbstractBoundary {
    GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(addAccommodationControl)

public:
    /**
     * 호스트의 숙소 등록 요청 핸들러
     * @param hostid
     * @param name
     * @param address
     * @param cost
     * @param date
     * @param opaqueCost
     */
    void createAccommodation(string hostid,string name, string address, int cost, string date, int opaqueCost);
};

#endif //SW_ENGINEERING_HW3_ADDACCOMMODATIONUI_H
