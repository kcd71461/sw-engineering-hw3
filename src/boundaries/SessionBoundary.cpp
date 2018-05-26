//
// Created by kimch on 5/26/2018.
//

#include "SessionBoundary.h"
#include "../controls/SessionControl.h"
#include "../SessionCollection.h"

void SessionBoundary::onChangeSession(char *id) {
    this->printLine("Session 변경");
    getSessionControl()->changeSession(string(id));
}

void SessionBoundary::onChangeGuestSession() {
    this->printLine("Guest session으로 변경");
    getSessionControl()->changeSessionToGuest();
}

SessionControl *SessionBoundary::getSessionControl() {
    return reinterpret_cast<SessionControl *>(this->getControl());
}
