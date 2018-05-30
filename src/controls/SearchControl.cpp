//
// Created by 심재철 on 18. 5. 27.
//

#include "SearchControl.h"
#include "../boundaries/SearchUI.h"
#include "../AccommodationCollection.h"
#include "../Accommodation.h"
#include "../Reservation.h"
#include "../ReservationCollection.h"
#include <string>

GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(SearchControl, SearchUI)
GENERATE_SINGLETON_IMPLEMENT(SearchControl)

void SearchControl::searchAccommodations(string address, string date) {
    AccommodationCollection *accommodations = AccommodationCollection::getInstance();
    string outputMessage = "";
    accommodations->sortbycost(); // 가격을 기준으로 오름차순 정렬
    for (int i = 0; i < accommodations->getSize(); i++) {
        Accommodation *accommo = accommodations->get(i);
        if (accommo->getAddress() == address && accommo->getDate() == date) {
            outputMessage += "> " + accommo->getHostid() + " " + accommo->getName() + " " + accommo->getAddress() + " " + to_string(accommo->getCost()) + "\n";
        }
    }

    this->getSearchUI()->print(outputMessage.c_str());

}

void SearchControl::addReservation(string hostid, string guestid, string accommoname) {
    AccommodationCollection *accommodationCollection = AccommodationCollection::getInstance();
    string name, address, date, outputMessage = "";
    int cost;
    Reservation *reservation;
    for (int i = 0; i < accommodationCollection->getSize(); i++) {
        Accommodation *accommodation = accommodationCollection->get(i);
        if (accommodation->getName() == accommoname) {
            name = accommodation->getName();
            address = accommodation->getAddress();
            date = accommodation->getDate();
            cost = accommodation->getCost();

            reservation = new Reservation(hostid, guestid, name, address, date, cost);
            ReservationCollection::getInstance()->add(reservation);
            outputMessage += "> " + hostid + " " + name + " " + address + " " + date + " " + to_string(cost) + "\n";

        }
    }
    this->getSearchUI()->print(outputMessage.c_str());
}