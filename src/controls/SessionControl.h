//
// Created by kimch on 5/26/2018.
//

#ifndef SW_ENGINEERING_HW3_SESSIONCONTROL_H
#define SW_ENGINEERING_HW3_SESSIONCONTROL_H


#include "AbstractControl.h"
#include "../boundaries/SessionBoundary.h"
class SessionBoundary;
class SessionControl : public AbstractControl {
private:
    static SessionControl *instance;

    SessionControl();

public:
    static SessionControl *getInstance();
    SessionBoundary *getSessionBoundary();

    void changeSession(string basic_string);

    void changeSessionToGuest();
};


#endif //SW_ENGINEERING_HW3_SESSIONCONTROL_H
