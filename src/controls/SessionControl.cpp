//
// Created by kimch on 5/26/2018.
//

#include "SessionControl.h"
#include "../SingletonMacro.h"
#include "../SessionCollection.h"

void SessionControl::changeSession(string userID) {

    SessionCollection::getInstance()->changeCurrentSession(userID);
}

void SessionControl::changeSessionToGuest() {
    SessionCollection::getInstance()->changeCurrentSessionToGuest();
}


GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(SessionControl,SessionUI)
GENERATE_SINGLETON_IMPLEMENT(SessionControl)