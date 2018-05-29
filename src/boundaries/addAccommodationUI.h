//
// Created by simjae on 18. 5. 27.
//

#ifndef SW_ENGINEERING_HW3_ADDACCOMMODATIONUI_H
#define SW_ENGINEERING_HW3_ADDACCOMMODATIONUI_H


#include "AbstractBoundary.h"

class addAccommodationControl;

class addAccommodationUI : public AbstractBoundary {
    GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(addAccommodationControl)

public:
    void createAccommodation(string hostid,string name, string address, int cost, string date, int opaqueCost);
};

#endif //SW_ENGINEERING_HW3_ADDACCOMMODATIONUI_H
