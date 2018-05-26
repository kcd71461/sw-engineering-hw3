//
// Created by kimch on 5/26/2018.
//

#ifndef SW_ENGINEERING_HW3_SESSION_H
#define SW_ENGINEERING_HW3_SESSION_H
#define GUEST_SESSION_MEMBER_POINTER NULL

#include <string>
#include "Member.h"

using namespace std;

class Session {
private:
    Member *member;
public:
    Session();

    Session(Member *member);

    bool isGuest();

    Member *getMember();
};


#endif //SW_ENGINEERING_HW3_SESSION_H
