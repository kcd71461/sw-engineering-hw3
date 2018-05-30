//
// Created by kimch on 2018-05-29.
//

#ifndef SW_ENGINEERING_HW3_WITHDRAWALCONTROL_H
#define SW_ENGINEERING_HW3_WITHDRAWALCONTROL_H

#include "../SingletonMacro.h"
#include "../boundaries/WithdrawalUI.h"
#include "AbstractControl.h"
class WithdrawalUI;

/**
 * 회원 탈퇴 Control
 */
class WithdrawalControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(WithdrawalControl)
GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(WithdrawalControl, WithdrawalUI)

public:
    /**
     * 회원 삭제 요청을 수행
     */
    void deleteMember();
};

#endif //SW_ENGINEERING_HW3_WITHDRAWALCONTROL_H
