//
// Created by 권영진 on 2018. 5. 28..
//

#include "OpaqueInventoryControl.h"
#include "../Reservation.h"
#include "../ReservationCollection.h"
#include "../AccommodationCollection.h"
#include "../SessionCollection.h"
#include "../Guest.h"
#include "../Time.h"


GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(OpaqueInventoryControl, OpaqueInventoryUI)
GENERATE_SINGLETON_IMPLEMENT(OpaqueInventoryControl)

string OpaqueInventoryControl::addOpaqueReservation(string hostid, string accommoname) {
    AccommodationCollection *accommodationCollection = AccommodationCollection::getInstance();
    string name, address, date, returnvalue;
    int cost;
    Reservation *reservation;
    for (int i = 0; i < accommodationCollection->getSize(); i++) {
        Accommodation *accommodation = accommodationCollection->get(i);
        if (accommodation->getName() == accommoname) {
            name = accommodation->getName();
            address = accommodation->getAddress();
            date = accommodation->getDate();
            cost = accommodation->getOpaqueCost();
            string guestid = SessionCollection::getInstance()->getCurrentSession()->getMember()->getID();
            reservation = new Reservation(hostid, guestid, name, address, date, cost);
            ReservationCollection::getInstance()->add(reservation);
            returnvalue += hostid + " " + name + " " + address + " " + date + " " + to_string(cost) + "\n";

        }
    }
    return returnvalue;
}

void OpaqueInventoryControl::tryOpaqueInventoryReservation(string address, string date, int opaqueCost) {

    Time::getCurrentTime(); //현재 시간 가져오기


    AccommodationCollection *accommodations = AccommodationCollection::getInstance();
    Accommodation *result = NULL;
    for (int i = 0; i < accommodations->getSize(); i++) {
        Accommodation *accommodation = accommodations->get(i);
        if (accommodation->getAddress() == address && accommodation->getDate() == date &&
            accommodation->getOpaqueCost() != 0) {
            if (result == NULL) {
                result = accommodation;
            } else if (accommodation->getOpaqueCost() < result->getOpaqueCost()) {
                result = accommodation;
            } else continue;
        } else continue;
    }

    if (result == NULL) {
        this->getOpaqueInventoryUI()->printLine("Opaque 예약이 가능한 숙소가 존재하지 않습니다.");
    } else {
        this->addOpaqueReservation(result->getHostid(), result->getName());

    }


}
// TODO: 필요한 Control 함수 구현
