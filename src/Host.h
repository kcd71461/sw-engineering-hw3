//
// Created by 김창덕 on 2018-05-28.
//

#ifndef SW_ENGINEERING_HW3_HOST_H
#define SW_ENGINEERING_HW3_HOST_H


#include "AccommodationCollection.h"
#include "Member.h"

/**
 * Host Type Member Class
 */
class Host : public Member {
public:
    /**
     * Host 생성자
     * @param name
     * @param securityNumber
     * @param address
     * @param id
     * @param password
     */
    Host(const string &name, const string &securityNumber, const string &address, const string &id, const string &password);
};

#endif //SW_ENGINEERING_HW3_HOST_H
