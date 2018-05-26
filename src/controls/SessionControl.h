//
// Created by kimch on 5/26/2018.
//

#ifndef SW_ENGINEERING_HW3_SESSIONCONTROL_H
#define SW_ENGINEERING_HW3_SESSIONCONTROL_H


#include "AbstractControl.h"
#include "../boundaries/SessionUI.h"
#include "../SingletonMacro.h"

class SessionUI;

class SessionControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(SessionControl)
GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(SessionControl, SessionUI)

public:
    void changeSession(string userID);
    void changeSessionToGuest();
};


#endif //SW_ENGINEERING_HW3_SESSIONCONTROL_H
