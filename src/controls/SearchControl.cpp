//
// Created by simjae on 18. 5. 27.
//

#include "SearchControl.h"
#include "../boundaries/SearchUI.h"
#include "../AccommodationCollection.h"
#include "../Accommodation.h"
#include "../Reservation.h"
#include "../ReservationCollection.h"

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
// TODO: 필요한 Control 함수 구현
