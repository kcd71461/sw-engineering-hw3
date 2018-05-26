//
// Created by kimch on 2018-05-26.
//

#include "MemberCollection.h"
#include "SingletonMacro.h"

MemberCollection *MemberCollection::instance = NULL;
GENERATE_GET_INSTANCE_IMPLEMENT(MemberCollection)

MemberCollection::MemberCollection() {
}
