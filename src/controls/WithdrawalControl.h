//
// Created by 심재철 on 2018-05-29.
//

#ifndef SW_ENGINEERING_HW3_WITHDRAWALCONTROL_H
#define SW_ENGINEERING_HW3_WITHDRAWALCONTROL_H

#include "../SingletonMacro.h"
#include "../boundaries/WithdrawalUI.h"
#include "AbstractControl.h"
class WithdrawalUI;

/**
 * 회원 탈퇴 기능 Control Class.
 */
class WithdrawalControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(WithdrawalControl)
GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(WithdrawalControl, WithdrawalUI)

public:
    /**
     * 탈퇴 조건을 체크하고 MemberCollection 에서 Member 삭제를 시도
     */
    void deleteMember();
};

#endif //SW_ENGINEERING_HW3_WITHDRAWALCONTROL_H
