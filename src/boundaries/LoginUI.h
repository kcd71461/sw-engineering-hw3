//
// Created by kimch on 5/27/2018.
//

#ifndef SW_ENGINEERING_HW3_LOGINUI_H
#define SW_ENGINEERING_HW3_LOGINUI_H

#include "AbstractBoundary.h"

class LoginControl;

class LoginUI : public AbstractBoundary {
GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(LoginControl)

public:
    void onRequestLogin(string id, string password);
};


#endif //SW_ENGINEERING_HW3_LOGINUI_H
