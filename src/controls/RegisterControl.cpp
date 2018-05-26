//
// Created by kimch on 5/27/2018.
//

#include "RegisterControl.h"
#include "../MemberCollection.h"

GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(RegisterControl, RegisterUI)

void RegisterControl::registerMember(MemberTypes type, string name, string securityNumber, string address, string id,
                                     string password) {
    Member *newMember = new Member(type, name, securityNumber, address, id, password);
    MemberCollection::getInstance()->add(newMember);
    this->getRegisterUI()->printLine("> %s %s %s %s %s %s",
                                     type == MemberTypes::Host ? "host" : "guest",
                                     name.c_str(),
                                     securityNumber.c_str(),
                                     address.c_str(),
                                     id.c_str(),
                                     password.c_str());
}

GENERATE_SINGLETON_IMPLEMENT(RegisterControl)