//
// Created by kimch on 2018-05-24.
//

#ifndef SW_ENGINEERING_HW3_GUEST_H
#define SW_ENGINEERING_HW3_GUEST_H


#include "Member.h"

class Guest : public Member {
public:
    Guest(const string &name, const string &securityNumber, const string &address, const string &id, const string &password);

    const string getLastOpaqueTryTime() const;

    void setLastOpaqueTryTime(const string &lastOpaqueTryTime);

private:
    string lastOpaqueTryTime;
};


#endif //SW_ENGINEERING_HW3_GUEST_H
