//
// Created by kimch on 5/27/2018.
//

#ifndef SW_ENGINEERING_HW3_REGISTERCONTROL_H
#define SW_ENGINEERING_HW3_REGISTERCONTROL_H

#include "../SingletonMacro.h"
#include "../boundaries/RegisterUI.h"
#include "AbstractControl.h"
#include "../Member.h"


class RegisterUI;

class RegisterControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(RegisterControl)

GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(RegisterControl, RegisterUI)

public:
    void registerMember(MemberTypes type, string name, string securityNumber, string address, string id,
                        string password);
};


#endif //SW_ENGINEERING_HW3_REGISTERCONTROL_H
