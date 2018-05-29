//
// Created by kimch on 2018-05-29.
//

#ifndef SW_ENGINEERING_HW3_WITHDRAWALUI_H
#define SW_ENGINEERING_HW3_WITHDRAWALUI_H

#include "AbstractBoundary.h"

class WithdrawalControl;

class WithdrawalUI : public AbstractBoundary {
GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(WithdrawalControl)

public:
    // TODO: 필요한 Boundary 함수 선언
    void onWithdrawalRequest();
};


#endif //SW_ENGINEERING_HW3_WITHDRAWALUI_H
