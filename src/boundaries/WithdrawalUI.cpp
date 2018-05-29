//
// Created by kimch on 2018-05-29.
//

#include "WithdrawalUI.h"
#include "WithdrawalUI.h"
#include "../controls/WithdrawalControl.h"

GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(WithdrawalUI, WithdrawalControl)

void WithdrawalUI::onWithdrawalRequest() {
    this->getWithdrawalControl()->deleteMember();
}
// TODO: 필요한 Boundary 함수 구현