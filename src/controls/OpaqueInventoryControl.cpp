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
            cost = accommodation->getOpaqueCost();
            string guestid = SessionCollection::getInstance()->getCurrentSession()->getMember()->getID();
            reservation = new Reservation(hostid, guestid, name, address, date, cost);
            ReservationCollection::getInstance()->add(reservation);
            returnvalue += "success " + hostid + " " + name + " " + address + " " + date + " " + to_string(opaqueCost) + "\n";
        }
    }
    return returnvalue;
}

void OpaqueInventoryControl::tryOpaqueInventoryReservation(string address, string date, int opaqueCost) {

    //OpaqueInventory 예약 최근 시도 확인 해봅시다.
    string currentTime = Time::getCurrentTime();
    string last_tryTime;
    if (this->getCurrentMember()->getType() == MemberTypes::GuestMember) {
        Guest *guest = static_cast<Guest *>(this->getCurrentMember());

        last_tryTime = guest->getLastOpaqueTryTime();
        string last_tryTime_trans = DateTimeUtils::addDays(last_tryTime, 1);

        if (last_tryTime.compare(NULL_TIME_STR) == 0 || last_tryTime_trans.compare(currentTime) < 0 || last_tryTime_trans.compare(currentTime) == 0) {
            guest->setLastOpaqueTryTime(currentTime);

            //예약 시작
            AccommodationCollection *accommodations = AccommodationCollection::getInstance();
            Accommodation *result = NULL;
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
                this->getOpaqueInventoryUI()->printLine("Opaque 예약이 가능한 숙소가 존재하지 않습니다.");
                this->getOpaqueInventoryUI()->printLine(currentTime.c_str());
                this->getOpaqueInventoryUI()->printLine(last_tryTime.c_str());
                this->getOpaqueInventoryUI()->printLine(last_tryTime_trans.c_str());
            } else {
                string resultMessage = this->addOpaqueReservation(result->getHostid(), result->getName(), opaqueCost);
                this->getOpaqueInventoryUI()->printLine(resultMessage.c_str());
            }
        } else {
            this->getOpaqueInventoryUI()->printLine("Try again in 24 hours");
            this->getOpaqueInventoryUI()->printLine(currentTime.c_str());
            this->getOpaqueInventoryUI()->printLine(last_tryTime.c_str());
            this->getOpaqueInventoryUI()->printLine(last_tryTime_trans.c_str());
        }

        /*else if(last_tryTime_trans < currentTime){
            this->getOpaqueInventoryUI()->printLine("Try again in 24 hours");
        }*/
    }

}
// TODO: 필요한 Control 함수 구현
