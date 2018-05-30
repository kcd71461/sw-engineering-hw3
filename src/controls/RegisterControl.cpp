//
// Created by 심재철 on 5/27/2018.
//

#include "RegisterControl.h"
#include "../MemberCollection.h"

GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(RegisterControl, RegisterUI)

void RegisterControl::registerMember(MemberTypes type, string name, string securityNumber, string address, string id,
                                     string password) {
    Member *newMember;

    switch (type) {
        case MemberTypes::HostMember: //호스트 회원으로 회원가입 하려고 하는 경우
            newMember = new Host(name, securityNumber, address, id, password);
            break;

        case MemberTypes::GuestMember: // 게스트 회원으로 회웍나입 하려고 하는 경우
            newMember = new Guest(name, securityNumber, address, id, password);
            break;
        default:
            this->getRegisterUI()->printLine("> unknown member type.");
            return;
    }
    MemberCollection::getInstance()->add(newMember); //멤버 컬렉션에 새로운 멤버 추가
    this->getRegisterUI()->printLine("> %s %s %s %s %s %s",
                                     type == MemberTypes::HostMember ? "host" : "guest",
                                     name.c_str(),
                                     securityNumber.c_str(),
                                     address.c_str(),
                                     id.c_str(),
                                     password.c_str()); //새로 추가된 멤버의 정보를 출력함.
}

GENERATE_SINGLETON_IMPLEMENT(RegisterControl)