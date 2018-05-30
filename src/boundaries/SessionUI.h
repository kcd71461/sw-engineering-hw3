//
// Created by 김창덕 on 5/26/2018.
//

#ifndef SW_ENGINEERING_HW3_SESSIONBOUNDARY_H
#define SW_ENGINEERING_HW3_SESSIONBOUNDARY_H


#include "AbstractBoundary.h"

class SessionControl;

/**
 * Session 관련 기능 Boundary Class.
 */
class SessionUI : public AbstractBoundary {
GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(SessionControl)

public:
    /**
     * 세션 변경 요청 핸들러
     */
    void onChangeSession(char *);

    /**
     * 개스트 세션 변경 요청 핸들러
     */
    void onChangeGuestSession();
};


#endif //SW_ENGINEERING_HW3_SESSIONBOUNDARY_H
