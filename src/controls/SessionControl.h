//
// Created by 김창덕 on 5/26/2018.
//

#ifndef SW_ENGINEERING_HW3_SESSIONCONTROL_H
#define SW_ENGINEERING_HW3_SESSIONCONTROL_H


#include "AbstractControl.h"
#include "../boundaries/SessionUI.h"
#include "../SingletonMacro.h"

class SessionUI;

/**
 * 세션 관련 명령을 수행
 */
class SessionControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(SessionControl)
GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(SessionControl, SessionUI)

public:
    /**
     * 세션 전환
     * @param userID
     */
    void changeSession(string userID);

    /**
     * Guest 세션 전환
     */
    void changeSessionToGuest();
};


#endif //SW_ENGINEERING_HW3_SESSIONCONTROL_H
