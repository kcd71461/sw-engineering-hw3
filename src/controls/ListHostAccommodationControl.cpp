//
// Created by 김창덕 on 2018-05-30.
//

#include "ListHostAccommodationControl.h"
#include "../AccommodationCollection.h"
#include "../ReservationCollection.h"

GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(ListHostAccommodationControl, ListHostAccommodationUI)

void ListHostAccommodationControl::listAccommodations() {
    Member *currentMember = this->getCurrentMember();
    if (currentMember == NULL || currentMember->getType() == MemberTypes::GuestMember) {
        this->getListHostAccommodationUI()->printLine("> Host계정로 로그인 하셔야 조회가 가능합니다.");
        return;
    }

    //등록된 숙소 조회(이용날짜가 빠른순으로 출력)
    // 3 2 커맨드 입력시  {숙소이름 숙소주소 가격 날짜 예약여부 opaque inventory 가격}* 출력
    /*
     *  3.2. 등록 숙소 조회
        > room1 seoul 100000 2018:05:20 X 70000
        > room2 seoul 100000 2018:05:21 X 70000
     * */
    AccommodationCollection *accommodationCollection = AccommodationCollection::getInstance();
    accommodationCollection->sortByDate();
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