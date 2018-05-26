//
// Created by kimch on 5/26/2018.
//

#include "SessionControl.h"
#include "../SingletonMacro.h"
#include "../SessionCollection.h"

SessionControl *SessionControl::instance = NULL;

SessionControl::SessionControl() : AbstractControl(new SessionBoundary) {}

SessionBoundary *SessionControl::getSessionBoundary() {
    return static_cast<SessionBoundary *>(this->getBoundary());
}

void SessionControl::changeSession(string id) {

    SessionCollection::getInstance()->changeCurrentSession(id);
}

void SessionControl::changeSessionToGuest() {
    SessionCollection::getInstance()->changeCurrentSessionToGuest();
}

GENERATE_GET_INSTANCE_IMPLEMENT(SessionControl)