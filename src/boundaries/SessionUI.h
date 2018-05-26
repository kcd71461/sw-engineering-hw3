//
// Created by kimch on 5/26/2018.
//

#ifndef SW_ENGINEERING_HW3_SESSIONBOUNDARY_H
#define SW_ENGINEERING_HW3_SESSIONBOUNDARY_H


#include "AbstractBoundary.h"

class SessionControl;

class SessionUI : public AbstractBoundary {
GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(SessionControl)

public:
    void onChangeSession(char *);
    void onChangeGuestSession();
};


#endif //SW_ENGINEERING_HW3_SESSIONBOUNDARY_H