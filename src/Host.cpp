//
// Created by 김창덕 on 2018-05-28.
//

#include "Host.h"

Host::Host(const string &name, const string &securityNumber, const string &address, const string &id, const string &password) : Member(MemberTypes::HostMember, name, securityNumber, address, id, password) {}
