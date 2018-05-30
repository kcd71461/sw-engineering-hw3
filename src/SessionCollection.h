//
// Created by 김창덕 on 5/26/2018.
//
//

#ifndef SW_ENGINEERING_HW3_SESSIONCOLLECTION_H
#define SW_ENGINEERING_HW3_SESSIONCOLLECTION_H

#include "Collection.h"
#include "Session.h"
#include "SingletonMacro.h"

using namespace std;

/**
 * Session Collection
 * 현재 로그인한 모든 사용자의 세션들과 Guest 세션을 가지고있다.
 * collection내에 Guest 세션은 반드시 하나만 존재한다.
 */
class SessionCollection : public Collection<Session> {
    GENERATE_SINGLETON_DECLARE(SessionCollection)
private:
    SessionCollection();

    /**
     * collection에서 guest session을 반환
     * @return guest session
     */
    Session *getGuestSession();

    /**
     * 현재 사용자의 session
     */
    Session *currentSession;
public:
    Session *getCurrentSession() const;

public:
    /**
     * 현재 세션을 변경한다.
     * @return 변경 성공 여부
     */
    bool changeCurrentSession(Session *);

    /**
     * 현재 세션을 id={userID} 사용자의 세션으로 변경한다.
     * @param userID 사용자ID
     * @return 변경 성공 여부
     */
    bool changeCurrentSession(string userID);

    /**
     * 현재 세션을 Guest 세션으로 변경한다.
     */
    void changeCurrentSessionToGuest();
};

#endif //SW_ENGINEERING_HW3_SESSIONCOLLECTION_H
