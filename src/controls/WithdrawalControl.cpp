//
// Created by kimch on 2018-05-29.
//

#include "WithdrawalControl.h"
#include "../MemberCollection.h"
#include "../SessionCollection.h"
#include "../Guest.h"
#include "../Host.h"
#include "../ReservationCollection.h"

GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(WithdrawalControl, WithdrawalUI)
GENERATE_SINGLETON_IMPLEMENT(WithdrawalControl)

void WithdrawalControl::deleteMember() {
    Member *member = SessionCollection::getInstance()->getCurrentSession()->getMember();
    if (member == NULL) {
        this->getWithdrawalUI()->printLine("> guest session입니다");
    }
    switch (member->getType()) {
        case MemberTypes::GuestMember: {
            // ReservationCollection::getInstance().
            break;
        }
        case MemberTypes::HostMember: {
            Host *host = static_cast<Host *>(member);
            break;
        }
    }

}
// TODO: 필요한 Control 함수 구현