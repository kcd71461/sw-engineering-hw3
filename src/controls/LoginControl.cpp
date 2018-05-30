//
// Created by 심재철 on 5/27/2018.
//

#include "LoginControl.h"
#include "../MemberCollection.h"
#include "../SessionCollection.h"
GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(LoginControl, LoginUI)

void LoginControl::tryLogin(string id, string password) {
    MemberCollection *members = MemberCollection::getInstance();


    for (int i = 0, length = members->getSize(); i < length; i++) {
        if (members->get(i)->getID().compare(id) == 0) { // 멤버 컬렉션에 이미 입력된 id를 갖는 회원이 존재 하는지 확인
            Member *member = NULL;
            member = members->get(i);
            if (member != NULL && member->equalsPassword(password)) { // 회원의 비밀번호가 입력된 비밀번호와 같은지 확인
                Session *newSession = new Session(member);
                SessionCollection *sessions = SessionCollection::getInstance();
                sessions->add(newSession); // 비밀번호가 제대로 입력된 경우 세션 추가
                sessions->changeCurrentSession(newSession); // 방금 추가된 세션으로 세션 변경
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