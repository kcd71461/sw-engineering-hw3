//
// Created by kimch on 5/27/2018.
//

#ifndef SW_ENGINEERING_HW3_REGISTERCONTROL_H
#define SW_ENGINEERING_HW3_REGISTERCONTROL_H

#include "../SingletonMacro.h"
#include "../boundaries/RegisterUI.h"
#include "AbstractControl.h"

class RegisterUI;

class RegisterControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(RegisterControl)

GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(RegisterControl, RegisterUI)
};


#endif //SW_ENGINEERING_HW3_REGISTERCONTROL_H
