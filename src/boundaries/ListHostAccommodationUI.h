//
// Created by kimch on 2018-05-30.
//

#ifndef SW_ENGINEERING_HW3_HOSTACCOMMODATIONLISTUI_H
#define SW_ENGINEERING_HW3_HOSTACCOMMODATIONLISTUI_H

#include "AbstractBoundary.h"

class ListHostAccommodationControl;

class ListHostAccommodationUI : public AbstractBoundary {
GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(ListHostAccommodationControl)

public:
    void onListAccommodation();
};


#endif //SW_ENGINEERING_HW3_HOSTACCOMMODATIONLISTUI_H
