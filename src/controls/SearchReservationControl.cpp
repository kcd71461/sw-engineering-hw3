//
// Created by 권영진 on 2018. 5. 28..
//
#include "../boundaries/SearchReservationUI.h"
#include "../controls/SearchReservationControl.h"
#include "../Reservation.h"
#include "../ReservationCollection.h"
#include "../Guest.h"
#include "../Member.h"
#include "../Session.h"
#include "../SessionCollection.h"

GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(SearchReservationUI,SearchReservationControl)
// TODO: 필요한 Boundary 함수 구현

string SearchReservationControl::SearchReservation(){
    ReservationCollection *reservations = ReservationCollection::getInstance();
    string result;
    SessionCollection *sessions = SessionCollection::getInstance();
    Session *currentSession = sessions->getCurrentSession();
    string gid = currentSession->getMember()->getID();

    for(int i=0; i<reservations->getSize(); i++) {
        Reservation *reserv = reservations->get(i);

        if (reserv->getGuesid() == gid) {
            result += reserv->getHostid() + " " + reserv->getName() + " " + reserv->getAddress() + " " +
                      reserv->getDate() + " " + to_string(reserv->getCost()) + "\n";
        } else continue;
    }
    return result;
}
