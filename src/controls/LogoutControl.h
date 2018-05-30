//
// Created by kimch on 5/27/2018.
//

#ifndef SW_ENGINEERING_HW3_LOGOUTCONTROL_H
#define SW_ENGINEERING_HW3_LOGOUTCONTROL_H

#include "../SingletonMacro.h"
#include "../boundaries/LogoutUI.h"
#include "AbstractControl.h"
class LogoutUI;

/**
 * 로그아웃 Control
 */
class LogoutControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(LogoutControl)
GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(LogoutControl, LogoutUI)

public:
    /**
     * 로그아웃을 시도함
     */
    void tryLogout();
};


#endif //SW_ENGINEERING_HW3_LOGOUTCONTROL_H
