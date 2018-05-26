//
// Created by kimch on 5/26/2018.
//

#include "SessionUI.h"
#include "../controls/SessionControl.h"
#include "../SessionCollection.h"

GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(SessionUI,SessionControl)

void SessionUI::onChangeSession(char *id) {
    getSessionControl()->changeSession(string(id));
}

void SessionUI::onChangeGuestSession() {
    getSessionControl()->changeSessionToGuest();
}