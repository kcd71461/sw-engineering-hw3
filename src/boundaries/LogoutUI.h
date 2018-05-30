//
// Created by 심재철 on 5/27/2018.
//

#ifndef SW_ENGINEERING_HW3_LOGOUTUI_H
#define SW_ENGINEERING_HW3_LOGOUTUI_H

#include "AbstractBoundary.h"

class LogoutControl;

/**
 * 비로그인 사용자의 로그아웃 기능 Boundary Class.
 */
class LogoutUI : public AbstractBoundary {
GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(LogoutControl)

public:
    /**
     * 회원의 로그아웃 요청 핸들러
     */
    void onRequestLogout();
};


#endif //SW_ENGINEERING_HW3_LOGOUTUI_H
