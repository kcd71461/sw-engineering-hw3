//
// Created by kimch on 2018-05-24.
//

#ifndef SW_ENGINEERING_HW3_MEMBERCOLLECTION_H
#define SW_ENGINEERING_HW3_MEMBERCOLLECTION_H

#include "Collection.h"
#include "Member.h"

using namespace std;

class MemberCollection : public Collection<Member> {
private:
    static MemberCollection *instance;

    MemberCollection();

public:
    static MemberCollection *getInstance();
};


#endif //SW_ENGINEERING_HW3_MEMBERCOLLECTION_H
