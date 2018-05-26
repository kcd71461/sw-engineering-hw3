//
// Created by kimch on 5/26/2018.
//

#ifndef SW_ENGINEERING_HW3_SESSIONBOUNDARY_H
#define SW_ENGINEERING_HW3_SESSIONBOUNDARY_H


#include "AbstractBoundary.h"

class SessionControl;
class SessionBoundary : public AbstractBoundary {
public:
    void onChangeSession(char *);

    void onChangeGuestSession();

    SessionControl* getSessionControl();
};


#endif //SW_ENGINEERING_HW3_SESSIONBOUNDARY_H
