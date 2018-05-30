//
// Created by 김창덕 on 2018-05-29.
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
    void onWithdrawalRequest();
};


#endif //SW_ENGINEERING_HW3_WITHDRAWALUI_H
