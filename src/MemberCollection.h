//
// Created by kimch on 2018-05-24.
//

#ifndef SW_ENGINEERING_HW3_MEMBERCOLLECTION_H
#define SW_ENGINEERING_HW3_MEMBERCOLLECTION_H

#include <list>
#include "Collection.h"
#include "Member.h"

using namespace std;

class MemberCollection : public Collection<Member> {
public :
    Member *get(int index);
    Member *add(Member *);
    void remove(int index);
    void remove(Member *pItem);
    int getSize();
};


#endif //SW_ENGINEERING_HW3_MEMBERCOLLECTION_H
