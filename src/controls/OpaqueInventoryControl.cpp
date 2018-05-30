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

//Opaque Inventory 예약
string OpaqueInventoryControl::addOpaqueReservation(string hostid, string accommoname, int opaqueCost) {
    AccommodationCollection *accommodationCollection = AccommodationCollection::getInstance();
    ReservationCollection *reservations = ReservationCollection::getInstance();
    string address, date, outputMessage;
    for (int i = 0; i < accommodationCollection->getSize(); i++) {
        Accommodation *accommodation = accommodationCollection->get(i);
        if (accommodation->getName() == accommoname) {
            address = accommodation->getAddress();
            date = accommodation->getDate();
            string guestid = this->getCurrentMember()->getID();
            Reservation *reservation = new Reservation(hostid, guestid, accommoname, address, date, opaqueCost);
            reservations->add(reservation);
            outputMessage =
                    "> Success " + hostid + " " + accommoname + " " + address + " " + date + " " + to_string(opaqueCost);
            break;
        }
    }
    return outputMessage;
}

//Opaque Inventory 예약 시도
void OpaqueInventoryControl::tryOpaqueInventoryReservation(string address, string date, int opaqueCost) {
    AccommodationCollection *accommodations = AccommodationCollection::getInstance();
    ReservationCollection *reservations = ReservationCollection::getInstance();
    Accommodation *result = NULL;

    // OpaqueInventory 예약 최근 시도 시간 확인
    string currentTime = Time::getCurrentTime();
    string last_tryTime;
    if (this->getCurrentMember()->getType() == MemberTypes::GuestMember) {
        Guest *guest = static_cast<Guest *>(this->getCurrentMember());

        last_tryTime = guest->getLastOpaqueTryTime();
        string nextTryTime = DateTimeUtils::addDays(last_tryTime, 1);

        //24시간 내에 한 번만 시도 가능
        if (last_tryTime.compare(NULL_TIME_STR) == 0 || nextTryTime.compare(currentTime) < 0 ||
            nextTryTime.compare(currentTime) == 0) {
            guest->setLastOpaqueTryTime(currentTime);

            // 예약 가능 숙소 검색
            for (int i = 0, accommodationsSize = accommodations->getSize(); i < accommodationsSize; i++) {
                //<editor-fold desc="예약이 된 숙소는 스킵한다.">
                Accommodation *accommodation = accommodations->get(i);
                bool reserved = false;
                for (int j = 0, reservationsSize = reservations->getSize(); j < reservationsSize; j++) {
                    Reservation *reservation = reservations->get(j);
                    if (reservation->getName() == accommodation->getName() &&
                        reservation->getAddress() == accommodation->getAddress() &&
                        reservation->getHostID() == accommodation->getHostid()) {
                        reserved = true;
                        break;
                    }
                }
                if (reserved) {
                    continue;
                }
                //</editor-fold>

                //도시명, 날짜 일치하고 OpaqueCost 값이 0이 아닌, 즉 OpaqueCost에 값이 들어있는 숙소 검색 및 날짜가 빠른 숙소 선택
                if (accommodation->getAddress() == address && accommodation->getDate() == date &&
                    accommodation->getOpaqueCost() != 0) {
                    if (accommodation->getOpaqueCost() < opaqueCost || accommodation->getOpaqueCost() == opaqueCost) {
                        if (result == NULL) {
                            result = accommodation;
                        } else if (accommodation->getDate() < result->getDate()) {
                            result = accommodation;
                        }
                    }
                }
            }
            if (result == NULL) {
                //만족하는 숙소가 없을 시
                this->getOpaqueInventoryUI()->printLine("> Try again in 24 hours");
            } else {
                //만족하는 숙소 있을 시
                string resultMessage = this->addOpaqueReservation(result->getHostid(), result->getName(), opaqueCost);
                this->getOpaqueInventoryUI()->printLine(resultMessage.c_str());
            }

        } else {
            this->getOpaqueInventoryUI()->printLine("> Opaque inventory 예약은 24시간에 한 번만 가능합니다.");
        }
    } else {
        this->getOpaqueInventoryUI()->printLine("> Guest 회원으로 로그인 하셔야 합니다.");
    }
}
