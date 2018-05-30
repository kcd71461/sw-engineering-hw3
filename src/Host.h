//
// Created by 김창덕 on 2018-05-28.
//

#ifndef SW_ENGINEERING_HW3_HOST_H
#define SW_ENGINEERING_HW3_HOST_H


#include "AccommodationCollection.h"
#include "Member.h"

class Host : public Member {
public:
    Host(const string &name, const string &securityNumber, const string &address, const string &id, const string &password);

    AccommodationCollection *getAccommodations();
};

#endif //SW_ENGINEERING_HW3_HOST_H
