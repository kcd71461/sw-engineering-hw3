//
// Created by kimch on 5/27/2018.
//

#include "LoginUI.h"
#include "../controls/LoginControl.h"

GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(LoginUI, LoginControl)

void LoginUI::onRequestLogin(string id, string password) {
    this->getLoginControl()->tryLogin(id,password);
}
