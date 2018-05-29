//
// Created by 권영진 on 2018. 5. 28..
//
#include "../boundaries/SearchReservationUI.h"
#include "../controls/SearchReservationControl.h"
#include "../Reservation.h"
#include "../ReservationCollection.h"
#include "../Guest.h"
#include "../Session.h"

GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(SearchReservationUI,SearchReservationControl)
// TODO: 필요한 Boundary 함수 구현

string SearchReservationControl::SearchReservation(){
    ReservationCollection *reservations = ReservationCollection::getInstance();
    string result;
    string gid = Session::getMember()->getid();

    for(int i=0; i<reservations->getSize(); i++){
        reservation* reserv = reservations->get(i);

        //if(reserv->)
    }

}
