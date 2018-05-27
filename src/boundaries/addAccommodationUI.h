//
// Created by simjae on 18. 5. 27.
//

#ifndef SW_ENGINEERING_HW3_ADDACCOMMODATIONUI_H
#define SW_ENGINEERING_HW3_ADDACCOMMODATIONUI_H


#include "boundaries/AbstractBoundary.h"

class addAccommodationControl;

class addAccommodationUI : public AbstractBoundary {
    GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(addAccommodationControl)

public:
    // TODO: 필요한 Boundary 함수 선언
    void onaddAccommodation(string basic_string, string basicString);
};

#endif //SW_ENGINEERING_HW3_addAccommodationUI_H


#endif //SW_ENGINEERING_HW3_ADDACCOMMODATIONUI_H
