//
// Created by 김창덕 on 5/26/2018.
//

#include "SessionControl.h"
#include "../SingletonMacro.h"
#include "../SessionCollection.h"

void SessionControl::changeSession(string userID) {
    if (SessionCollection::getInstance()->changeCurrentSession(userID)) { // 현재 세션을 변경하려고 하는 id의 세션으로 변경
        this->getSessionUI()->printLine("> %s",
                                        SessionCollection::getInstance()->getCurrentSession()->getMember()->getID().c_str());
    } else {
        this->getSessionUI()->printLine("> session 변경 실패");
    }
}

void SessionControl::changeSessionToGuest() {
    SessionCollection::getInstance()->changeCurrentSessionToGuest(); //현재 세션을 게스트 세션으로 변경.
}


GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(SessionControl, SessionUI)
GENERATE_SINGLETON_IMPLEMENT(SessionControl)