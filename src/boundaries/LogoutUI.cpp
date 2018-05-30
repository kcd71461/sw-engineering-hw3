//
// Created by 심재철 on 5/27/2018.
//

#include "LogoutUI.h"
#include "../controls/LogoutControl.h"

GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(LogoutUI, LogoutControl)

void LogoutUI::onRequestLogout() {
    this->getLogoutControl()->tryLogout();
}
