//
// Created by kimch on 2018-05-29.
//

#ifndef SW_ENGINEERING_HW3_WITHDRAWALCONTROL_H
#define SW_ENGINEERING_HW3_WITHDRAWALCONTROL_H

#include "../SingletonMacro.h"
#include "../boundaries/WithdrawalUI.h"
#include "AbstractControl.h"
class WithdrawalUI;

class WithdrawalControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(WithdrawalControl)
GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(WithdrawalControl, WithdrawalUI)

public:
    // TODO: 필요한 Control 함수 선언
    void deleteMember();
};

#endif //SW_ENGINEERING_HW3_WITHDRAWALCONTROL_H
