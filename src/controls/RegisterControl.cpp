//
// Created by 김창덕 on 5/27/2018.
//

#include "RegisterControl.h"
#include "../MemberCollection.h"

GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(RegisterControl, RegisterUI)

void RegisterControl::registerMember(MemberTypes type, string name, string securityNumber, string address, string id,
                                     string password) {
    Member *newMember;

    switch (type) {
        case MemberTypes::HostMember:
            newMember = new Host(name, securityNumber, address, id, password);
            break;

        case MemberTypes::GuestMember:
            newMember = new Guest(name, securityNumber, address, id, password);
            break;
        default:
            this->getRegisterUI()->printLine("> unknown member type.");
            return;
    }
    MemberCollection::getInstance()->add(newMember);
    this->getRegisterUI()->printLine("> %s %s %s %s %s %s",
                                     type == MemberTypes::HostMember ? "host" : "guest",
                                     name.c_str(),
                                     securityNumber.c_str(),
                                     address.c_str(),
                                     id.c_str(),
                                     password.c_str());
}

GENERATE_SINGLETON_IMPLEMENT(RegisterControl)