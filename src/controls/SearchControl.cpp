//
// Created by simjae on 18. 5. 27.
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

string SearchControl::searchAccommodations(string address, string date) {
    AccommodationCollection *accommodations = AccommodationCollection::getInstance();
    string returnvalue;
    for(int i=0; i<accommodations->getSize(); i++ ){
        Accommodation* accommo = accommodations->get(i);
        if(accommo->getAddress() == address && accommo->getDate() == date){
            returnvalue += accommo->getHostid()+" "+accommo->getName()+" "+accommo->getAddress()+" "+to_string(accommo->getCost())+"\n";
        }
    }
    return returnvalue;
    // this->getSearchUI()->printLine()

}

string SearchControl::addReservation(string hostid, string accommoname) {
    AccommodationCollection* accommodationCollection = AccommodationCollection::getInstance();
    string name,address,date,returnvalue;
    int cost;
    Reservation* reservation;
    for(int i=0; i<accommodationCollection->getSize(); i++){
        Accommodation* accommodation = accommodationCollection->get(i);
        if(accommodation->getName() == accommoname){
            name = accommodation->getName();
            address = accommodation->getAddress();
            date = accommodation->getDate();
            cost = accommodation->getCost();

            reservation = new Reservation(hostid,name,address,date,cost);
            ReservationCollection::getInstance()->add(reservation);
            returnvalue += hostid+" "+name+" "+address+" "+date+" "+to_string(cost)+"\n";

        }
    }
    return returnvalue;
}

string SearchControl::getAllAccommodations() {
    string returnvalue;

    AccommodationCollection* accommodationCollection = AccommodationCollection::getInstance();
    ReservationCollection* reservationCollection = ReservationCollection::getInstance();
    for(int i=0; i<accommodationCollection->getSize(); i++){
        Accommodation* accommodation = accommodationCollection->get(i);
        bool check = false;
        for(int j=0; j<reservationCollection->getSize(); j++){
            Reservation* reservation = reservationCollection->get(j);
            if(accommodation->getName() == reservation->getName())
                check = true; //예약 컬렉션에 있는 모든 예약에 대해 현재 숙소가 있는지를 검사
        }
        if(check)
            returnvalue += accommodation->getName() + " " + accommodation->getAddress() + " " + to_string(accommodation->getCost()) + " " + accommodation->getDate()+" "+"O"+" "+to_string(accommodation->getOpaqueCost()) +"\n";
        else
            returnvalue += accommodation->getName() + " " + accommodation->getAddress() + " " + to_string(accommodation->getCost()) + " " + accommodation->getDate()+" "+"X"+" "+to_string(accommodation->getOpaqueCost()) +"\n";

    }

    return returnvalue;
}
// TODO: 필요한 Control 함수 구현
