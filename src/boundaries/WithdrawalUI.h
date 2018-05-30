//
// Created by 심재철 on 2018-05-29.
//

#ifndef SW_ENGINEERING_HW3_WITHDRAWALUI_H
#define SW_ENGINEERING_HW3_WITHDRAWALUI_H

#include "AbstractBoundary.h"

class WithdrawalControl;

/**
 * 회원 탈퇴 기능 Boundary Class.
 */
class WithdrawalUI : public AbstractBoundary {
GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(WithdrawalControl)

public:
    /**
     * 회원 탈퇴 요청 핸들러
     */
    void onWithdrawalRequest();
};


#endif //SW_ENGINEERING_HW3_WITHDRAWALUI_H
