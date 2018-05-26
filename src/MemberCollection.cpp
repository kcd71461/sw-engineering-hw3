//
// Created by kimch on 2018-05-26.
//

#include "MemberCollection.h"
#include "SingletonMacro.h"

MemberCollection *MemberCollection::instance = NULL;
GENERATE_SINGLETON_IMPLEMENT(MemberCollection)

MemberCollection::MemberCollection() {
}
