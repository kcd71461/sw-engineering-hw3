//
// Created by kimch on 2018-05-26.
//

#include "MemberCollection.h"

MemberCollection *MemberCollection::instance = NULL;
MemberCollection *MemberCollection::getInstance() {
    if (instance == NULL) {
        instance = new MemberCollection();
    }
    return instance;
}

MemberCollection::MemberCollection() {
}
