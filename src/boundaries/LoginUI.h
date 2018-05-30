//
// Created by 김창덕 on 5/27/2018.
//

#ifndef SW_ENGINEERING_HW3_LOGINUI_H
#define SW_ENGINEERING_HW3_LOGINUI_H

#include "AbstractBoundary.h"

class LoginControl;

/**
 * 비로그인 사용자의 Login Boundary 클래스
 */
class LoginUI : public AbstractBoundary {
GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(LoginControl)

public:
    /**
     * 비로그인 사용자가 로그인 요청
     * @param id
     * @param password
     */
    void onRequestLogin(string id, string password);
};


#endif //SW_ENGINEERING_HW3_LOGINUI_H
