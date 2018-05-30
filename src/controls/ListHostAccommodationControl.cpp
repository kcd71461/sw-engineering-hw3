//
// Created by 김창덕 on 2018-05-30.
//

#include "ListHostAccommodationControl.h"
#include "../AccommodationCollection.h"
#include "../ReservationCollection.h"

GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(ListHostAccommodationControl, ListHostAccommodationUI)

void ListHostAccommodationControl::listAccommodations() {
    Member *currentMember = this->getCurrentMember();
    if (currentMember == NULL || currentMember->getType() == MemberTypes::GuestMember) { //현재 세션이 Host 세션인 경우
        this->getListHostAccommodationUI()->printLine("> Host계정로 로그인 하셔야 조회가 가능합니다.");
        return;
    }

    AccommodationCollection *accommodationCollection = AccommodationCollection::getInstance();
    accommodationCollection->sortByDate(); // 숙소 컬렉션에 존재하는 숙소들을 날짜를 기준으로 오름차순 정렬
    ReservationCollection *reservationCollection = ReservationCollection::getInstance();
    for (int i = 0; i < accommodationCollection->getSize(); i++) {
        Accommodation *accommodation = accommodationCollection->get(i);
        if (accommodation == NULL || accommodation->getHostid().compare(currentMember->getID()) != 0) {
            continue;
        }
        bool check = false;
        for (int j = 0; j < reservationCollection->getSize(); j++) {
            Reservation *reservation = reservationCollection->get(j);
            if (accommodation->getName() == reservation->getName())
                check = true; //예약 컬렉션에 있는 모든 예약에 대해 현재 숙소가 있는지를 검사
        }
        this->getListHostAccommodationUI()->printLine("> %s %s %d %s %s %d",
                                                      accommodation->getName().c_str(),
                                                      accommodation->getAddress().c_str(),
                                                      accommodation->getCost(),
                                                      accommodation->getDate().c_str(),
                                                      check ? "O" : "X",
                                                      accommodation->getOpaqueCost()
        );
    }
}

GENERATE_SINGLETON_IMPLEMENT(ListHostAccommodationControl)