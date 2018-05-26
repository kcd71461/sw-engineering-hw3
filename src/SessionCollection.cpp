//
// Created by kimch on 5/26/2018.
//

#include "SessionCollection.h"
#include "SingletonMacro.h"

GENERATE_SINGLETON_IMPLEMENT(SessionCollection)

SessionCollection::SessionCollection() {
    // collection 첫번째는 GUEST 세션
    this->add(new Session());
}

Session *SessionCollection::getGuestSession() {
    return this->get(0);
}

bool SessionCollection::changeCurrentSession(Session *session) {
    if (this->exists(session)) {
        this->currentSession = session;
        return true;
    }
    return false;
}

bool SessionCollection::changeCurrentSession(string userID) {
    for (int i = 0, length = this->getSize(); i < length; i++) {
        if (this->get(i)->getMember()->getName().compare(userID)) {
            return this->changeCurrentSession(this->get(i));
        }
    }
    return false;
}

void SessionCollection::changeCurrentSessionToGuest() {
    this->currentSession = getGuestSession();
}