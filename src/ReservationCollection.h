//
// Created by 김창덕 on 2018-05-24.
//

#ifndef SW_ENGINEERING_HW3_RESERVATIONCOLLECTION_H
#define SW_ENGINEERING_HW3_RESERVATIONCOLLECTION_H

#include "SingletonMacro.h"
#include "Collection.h"
#include "Reservation.h"

using namespace std;

/**
 * Reservation List의 Wrapper Class. Singleton.
 */
class ReservationCollection : public Collection<Reservation> {
    GENERATE_SINGLETON_DECLARE(ReservationCollection)
private:
    ReservationCollection();
};


#endif //SW_ENGINEERING_HW3_RESERVATION_H