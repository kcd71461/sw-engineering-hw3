//
// Created by 김창덕 on 2018-05-24.
//

#ifndef SW_ENGINEERING_HW3_MEMBERCOLLECTION_H
#define SW_ENGINEERING_HW3_MEMBERCOLLECTION_H

#include "Collection.h"
#include "Member.h"
#include "SingletonMacro.h"

using namespace std;

/**
 * Member List의 Wrapper Class. Singleton.
 */
class MemberCollection : public Collection<Member> {
GENERATE_SINGLETON_DECLARE(MemberCollection)
private:
    MemberCollection();
};


#endif //SW_ENGINEERING_HW3_MEMBERCOLLECTION_H
