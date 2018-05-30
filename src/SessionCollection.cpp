//
// Created by 김창덕 on 5/26/2018.
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
        Session *session = this->get(i);
        if (!session->isGuest() && session->getMember()->getID().compare(userID) == 0) {
            return this->changeCurrentSession(session);
        }
    }
    return false;
}

void SessionCollection::changeCurrentSessionToGuest() {
    this->currentSession = getGuestSession();
}

Session *SessionCollection::getCurrentSession() const {
    return currentSession;
}
