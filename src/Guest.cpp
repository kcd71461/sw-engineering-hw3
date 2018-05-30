//
// Created by 김창덕 on 2018-05-28.
//

#include "Guest.h"
#include "DateTimeUtils.h"

Guest::Guest(const string &name, const string &securityNumber, const string &address, const string &id, const string &password) : Member(MemberTypes::GuestMember, name, securityNumber, address, id, password) {
    lastOpaqueTryTime = NULL_TIME_STR;
}

const string Guest::getLastOpaqueTryTime() const {
    return lastOpaqueTryTime;
}

void Guest::setLastOpaqueTryTime(const string &lastOpaqueTryTime) {
    Guest::lastOpaqueTryTime = lastOpaqueTryTime;
}
