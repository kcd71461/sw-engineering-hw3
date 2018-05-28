//
// Created by kimch on 2018-05-28.
//

#include "Guest.h"

Guest::Guest(const string &name, const string &securityNumber, const string &address, const string &id, const string &password) : Member(MemberTypes::GuestMember, name, securityNumber, address, id, password) {}

const string &Guest::getLastOpaqueTryTime() const {
    return lastOpaqueTryTime;
}

void Guest::setLastOpaqueTryTime(const string &lastOpaqueTryTime) {
    Guest::lastOpaqueTryTime = lastOpaqueTryTime;
}
