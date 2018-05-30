//
// Created by 김창덕 on 2018-05-24.
//

#ifndef SW_ENGINEERING_HW3_GUEST_H
#define SW_ENGINEERING_HW3_GUEST_H


#include "Member.h"

/**
 * Guest Type Member Class.
 */
class Guest : public Member {
public:
    Guest(const string &name, const string &securityNumber, const string &address, const string &id, const string &password);

    const string getLastOpaqueTryTime() const;

    void setLastOpaqueTryTime(const string &lastOpaqueTryTime);

private:
    /**
     * 마지막 Opaque 예약 시도 시간
     */
    string lastOpaqueTryTime;
};


#endif //SW_ENGINEERING_HW3_GUEST_H
