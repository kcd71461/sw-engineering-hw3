//
// Created by kimch on 5/27/2018.
//

#include "RegisterUI.h"
#include "../controls/RegisterControl.h"

GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(RegisterUI, RegisterControl)

void RegisterUI::onRegisterRequest(MemberTypes type, string name, string securityNumber, string address, string id,
                                   string password) {
    this->getRegisterControl()->registerMember(type, name, securityNumber, address, id,
                                               password);
}
