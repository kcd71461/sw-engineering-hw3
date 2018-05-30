//
// Created by 김창덕 on 5/26/2018.
//

#include "Session.h"

/**
 * Guest 세션 생성자.
 */
Session::Session() {
    this->member = GUEST_SESSION_MEMBER_POINTER;
}

/**
 * 로그인 사용자 세션
 * @param member
 */
Session::Session(Member *member) {
    this->member = member;
}

bool Session::isGuest() {
    return this->member == GUEST_SESSION_MEMBER_POINTER;
}

Member* Session::getMember() {
    return this->member;
}
