//
// Created by 김창덕 on 5/27/2018.
//

#ifndef SW_ENGINEERING_HW3_LOGINCONTROL_H
#define SW_ENGINEERING_HW3_LOGINCONTROL_H

#include "../SingletonMacro.h"
#include "../boundaries/LoginUI.h"
#include "AbstractControl.h"
class LoginUI;

/**
 * 로그인 기능 Control Class.
 */
class LoginControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(LoginControl)
GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(LoginControl, LoginUI)

public:
    /**
     * Login을 시도
     * @param id
     * @param password
     */
    void tryLogin(string id, string password);
};


#endif //SW_ENGINEERING_HW3_LOGINCONTROL_H
