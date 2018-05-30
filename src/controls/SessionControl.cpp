//
// Created by 김창덕 on 5/26/2018.
//

#include "SessionControl.h"
#include "../SingletonMacro.h"
#include "../SessionCollection.h"

void SessionControl::changeSession(string userID) {
    if (SessionCollection::getInstance()->changeCurrentSession(userID)) {
        this->getSessionUI()->printLine("> %s",
                                        SessionCollection::getInstance()->getCurrentSession()->getMember()->getID().c_str());
    } else {
        this->getSessionUI()->printLine("> session 변경 실패");
    }
}

void SessionControl::changeSessionToGuest() {
    SessionCollection::getInstance()->changeCurrentSessionToGuest();
}


GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(SessionControl, SessionUI)
GENERATE_SINGLETON_IMPLEMENT(SessionControl)