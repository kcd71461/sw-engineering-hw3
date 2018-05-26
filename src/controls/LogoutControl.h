//
// Created by kimch on 5/27/2018.
//

#ifndef SW_ENGINEERING_HW3_LOGOUTCONTROL_H
#define SW_ENGINEERING_HW3_LOGOUTCONTROL_H

#include "../SingletonMacro.h"
#include "../boundaries/LogoutUI.h"
#include "AbstractControl.h"
class LogoutUI;

class LogoutControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(LogoutControl)
GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(LogoutControl, LogoutUI)

public:
    // TODO: 필요한 Control 함수 선언
    void tryLogout();
};


#endif //SW_ENGINEERING_HW3_LOGOUTCONTROL_H
