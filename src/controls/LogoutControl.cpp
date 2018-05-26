//
// Created by kimch on 5/27/2018.
//

#include "LogoutControl.h"
#include "../SessionCollection.h"
GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(LogoutControl, LogoutUI)

void LogoutControl::tryLogout() {
    SessionCollection *sessions = SessionCollection::getInstance();
    Session *currentSession = sessions->getCurrentSession();
    if (currentSession->isGuest()) {
        this->getLogoutUI()->printLine("> 현재 guest 세션이므로 로그아웃 할 수 없습니다.");
    } else {
        string id = currentSession->getMember()->getID();
        sessions->remove(currentSession);
        sessions->changeCurrentSessionToGuest();
        this->getLogoutUI()->printLine("> %s", id.c_str());
    }
}

GENERATE_SINGLETON_IMPLEMENT(LogoutControl)