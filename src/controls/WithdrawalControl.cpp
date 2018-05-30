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
    Member *member = this->getCurrentMember();

    if (member == NULL) {
        this->getWithdrawalUI()->printLine("> guest session입니다");
        return;
    }

    string id = member->getID();
    bool removable = true;
    switch (member->getType()) {
        case MemberTypes::GuestMember: {
            ReservationCollection *reservations = ReservationCollection::getInstance();
            for (int i = 0, length = reservations->getSize(); i < length; i++) {
                Reservation *reservation = reservations->get(i);
                if (reservation->getGuestID().compare(id) == 0 && reservation->getDate().compare(Time::getCurrentTime()) >= 0) {
                    removable = false;
                    this->getWithdrawalUI()->printLine("> 예약이 있습니다.");
                    break;
                }
            }
            break;
        }
        case MemberTypes::HostMember: {
            AccommodationCollection *accommodations = AccommodationCollection::getInstance();
            for (int i = 0, length = accommodations->getSize(); i < length; i++) {
                Accommodation *accommodation = accommodations->get(i);
                if (accommodation->getHostid().compare(member->getID()) != 0) {
                    continue;
                } else {
                    removable = false;
                    this->getBoundary()->printLine("> 등록된 숙소가 존재합니다.");
                    break;
                }
            }
            break;
        }
    }
    if (removable) {
        MemberCollection::getInstance()->remove(member);
        this->getWithdrawalUI()->printLine("> %s", id.c_str());
        SessionCollection::getInstance()->changeCurrentSessionToGuest();
    }

}