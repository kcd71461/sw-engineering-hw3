//
// Created by 권영진 on 2018. 5. 28..
//

#include "OpaqueInventoryControl.h"
#include "../Reservation.h"
#include "../ReservationCollection.h"
#include "../AccommodationCollection.h"
#include "../SessionCollection.h"
#include "../Guest.h"
#include "../DateTimeUtils.h"
#include "../Time.h"


GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(OpaqueInventoryControl, OpaqueInventoryUI)
GENERATE_SINGLETON_IMPLEMENT(OpaqueInventoryControl)

string OpaqueInventoryControl::addOpaqueReservation(string hostid, string accommoname, int opaqueCost) {
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
            string guestid = SessionCollection::getInstance()->getCurrentSession()->getMember()->getID();
            reservation = new Reservation(hostid, guestid, name, address, date, opaqueCost);
            ReservationCollection::getInstance()->add(reservation);
            returnvalue += "> Success " + hostid + " " + name + " " + address + " " + date + " " + to_string(opaqueCost) + "\n";
        }
    }
    return returnvalue;
}

void OpaqueInventoryControl::tryOpaqueInventoryReservation(string address, string date, int opaqueCost) {
    // 예약 시작
    AccommodationCollection *accommodations = AccommodationCollection::getInstance();
    Accommodation *result = NULL;


    // OpaqueInventory 예약 최근 시도 확인 해봅시다.
    string currentTime = Time::getCurrentTime();
    string last_tryTime;
    if (this->getCurrentMember()->getType() == MemberTypes::GuestMember) {
        Guest *guest = static_cast<Guest *>(this->getCurrentMember());

        last_tryTime = guest->getLastOpaqueTryTime();
        string nextTryTime = DateTimeUtils::addDays(last_tryTime, 1);

        if (last_tryTime.compare(NULL_TIME_STR) == 0 || nextTryTime.compare(currentTime) < 0 || nextTryTime.compare(currentTime) == 0) {
            guest->setLastOpaqueTryTime(currentTime);

            // 예약 가능 숙소 검색
            for (int i = 0; i < accommodations->getSize(); i++) {
                Accommodation *accommodation = accommodations->get(i);

                if (accommodation->getAddress() == address && accommodation->getDate() == date &&
                    accommodation->getOpaqueCost() != 0) {
                    if (accommodation->getOpaqueCost() < opaqueCost || accommodation->getOpaqueCost() == opaqueCost) {
                        if (result == NULL) {
                            result = accommodation;
                        } else if (accommodation->getDate() < result->getDate()) {
                            result = accommodation;
                        } else continue;
                    } else continue;
                } else continue;
            }
            if (result == NULL) {
                this->getOpaqueInventoryUI()->printLine("> Try again in 24 hours");
            } else {
                string resultMessage = this->addOpaqueReservation(result->getHostid(), result->getName(), opaqueCost);
                this->getOpaqueInventoryUI()->print(resultMessage.c_str());
            }

        }
        else this->getOpaqueInventoryUI()->printLine("> Opaque inventory 예약은 24시간에 한 번만 가능합니다.");
    }

}
// TODO: 필요한 Control 함수 구현
