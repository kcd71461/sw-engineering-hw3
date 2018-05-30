//
// Created by 김창덕 on 2018-05-24.
//

#include "Member.h"

Member::Member(MemberTypes type, string name, string securityNumber, string address, string id, string password) {
    this->type = type;
    this->name = name;
    this->securityNumber = securityNumber;
    this->address = address;
    this->id = id;
    this->password = password;
}

MemberTypes Member::getType() {
    return this->type;
}

string Member::getName() {
    return this->name;
}

string Member::getAddress() {
    return this->address;
}

string Member::getID() {
    return this->id;
}

bool Member::equalsPassword(string password) {
    return this->password.compare(password) == 0;
}
