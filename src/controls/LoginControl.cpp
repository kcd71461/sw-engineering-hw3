//
// Created by kimch on 5/27/2018.
//

#include "LoginControl.h"
#include "../MemberCollection.h"
#include "../SessionCollection.h"
GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(LoginControl, LoginUI)

void LoginControl::tryLogin(string id, string password) {
    MemberCollection *members = MemberCollection::getInstance();


    for (int i = 0, length = members->getSize(); i < length; i++) {
        if (members->get(i)->getID().compare(id) == 0) {
            Member *member = NULL;
            member = members->get(i);
            if (member != NULL && member->equalsPassword(password)) {
                Session *newSession = new Session(member);
                SessionCollection *sessions = SessionCollection::getInstance();
                sessions->add(newSession);
                sessions->changeCurrentSession(newSession);
                this->getLoginUI()->printLine("> %s %s", id.c_str(), password.c_str());
            } else {
                if (member == NULL) {
                    this->getLoginUI()->printLine("> 해당 ID 회원이 존재하지 않습니다.");
                } else {
                    this->getLoginUI()->printLine("> 패스워드가 틀립니다.");
                }
            }
            break;
        }
    }
}

GENERATE_SINGLETON_IMPLEMENT(LoginControl)