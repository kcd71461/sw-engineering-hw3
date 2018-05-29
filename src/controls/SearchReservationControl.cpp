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

GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(SearchReservationControl, SearchReservationUI)
GENERATE_SINGLETON_IMPLEMENT(SearchReservationControl)

void SearchReservationControl::SearchReservation() {
    ReservationCollection *reservations = ReservationCollection::getInstance();
    string outputMessage = "";
    SessionCollection *sessions = SessionCollection::getInstance();
    Session *currentSession = sessions->getCurrentSession();
    string gid = currentSession->getMember()->getID();

    for (int i = 0; i < reservations->getSize(); i++) {
        Reservation *reserv = reservations->get(i);

        if (reserv->getGuestID() == gid) {
            outputMessage += "> " + reserv->getHostID() + " " + reserv->getName() + " " + reserv->getAddress() + " " +
                             reserv->getDate() + " " + to_string(reserv->getCost()) + "\n";
        } else continue;
    }
    this->getSearchReservationUI()->print(outputMessage.c_str());
}
