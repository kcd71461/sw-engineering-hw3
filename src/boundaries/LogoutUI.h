//
// Created by kimch on 5/27/2018.
//

#ifndef SW_ENGINEERING_HW3_LOGOUTUI_H
#define SW_ENGINEERING_HW3_LOGOUTUI_H

#include "AbstractBoundary.h"

class LogoutControl;

class LogoutUI : public AbstractBoundary {
GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(LogoutControl)

public:
    // TODO: 필요한 Boundary 함수 선언
    void onRequestLogout();
};


#endif //SW_ENGINEERING_HW3_LOGOUTUI_H
