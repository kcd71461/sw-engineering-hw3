//
// Created by 김창덕 on 5/27/2018.
//

#include "LogoutControl.h"
#include "../SessionCollection.h"
GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(LogoutControl, LogoutUI)

void LogoutControl::tryLogout() {
    SessionCollection *sessions = SessionCollection::getInstance();
    Session *currentSession = sessions->getCurrentSession();

    if (currentSession->isGuest()) { // 현재 세션이 Guest이면 로그아웃 불가
        this->getLogoutUI()->printLine("> 현재 guest 세션이므로 로그아웃 할 수 없습니다.");
    } else {
        // 현재 세션 삭제 후 Guest 세션으로 전환
        string id = currentSession->getMember()->getID();
        sessions->remove(currentSession);
        sessions->changeCurrentSessionToGuest();
        this->getLogoutUI()->printLine("> %s", id.c_str());
    }
}

GENERATE_SINGLETON_IMPLEMENT(LogoutControl)