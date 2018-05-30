//
// Created by 심재철 on 2018-05-29.
//

#include "WithdrawalUI.h"
#include "WithdrawalUI.h"
#include "../controls/WithdrawalControl.h"

GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(WithdrawalUI, WithdrawalControl)

void WithdrawalUI::onWithdrawalRequest() {
    this->getWithdrawalControl()->deleteMember();
}