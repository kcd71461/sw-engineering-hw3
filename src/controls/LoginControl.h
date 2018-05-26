//
// Created by kimch on 5/27/2018.
//

#ifndef SW_ENGINEERING_HW3_LOGINCONTROL_H
#define SW_ENGINEERING_HW3_LOGINCONTROL_H

#include "../SingletonMacro.h"
#include "../boundaries/LoginUI.h"
#include "AbstractControl.h"
class LoginUI;

class LoginControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(LoginControl)
GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(LoginControl, LoginUI)

public:
    // TODO: 필요한 Control 함수 선언
    void tryLogin(string id, string password);
};


#endif //SW_ENGINEERING_HW3_LOGINCONTROL_H
