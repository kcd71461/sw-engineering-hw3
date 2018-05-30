//
// Created by 심재철 on 2018-05-29.
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

    if (member == NULL) { //현재 guest session(non member)인 경우
        this->getWithdrawalUI()->printLine("> guest session입니다");
        return;
    }

    string id = member->getID();
    bool removable = true;
    switch (member->getType()) {
        case MemberTypes::GuestMember: { // 게스트 회원에 대한 회원 탈퇴를 하려고 하는 경우
            ReservationCollection *reservations = ReservationCollection::getInstance();
            for (int i = 0, length = reservations->getSize(); i < length; i++) { // 그 게스트 회원이 예약한 숙소가 있는지 확인
                Reservation *reservation = reservations->get(i);
                if (reservation->getGuestID().compare(id) == 0 && reservation->getDate().compare(Time::getCurrentTime()) >= 0) { //게스트 회원으로 예약된 숙소가 있고 그 숙소의 예약일이 현재 시간 이후인 경우
                    removable = false;
                    this->getWithdrawalUI()->printLine("> 예약이 있습니다.");
                    break;
                }
            }
            break;
        }
        case MemberTypes::HostMember: { // 호스트 회원에 대한 회원 탈퇴를 하는 경우
            AccommodationCollection *accommodations = AccommodationCollection::getInstance();
            for (int i = 0, length = accommodations->getSize(); i < length; i++) { // 호스트 회원의 숙소가 있는 경우 탈퇴 불가능.
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