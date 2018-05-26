//
// Created by kimch on 5/27/2018.
//

#ifndef SW_ENGINEERING_HW3_REGISTERUI_H
#define SW_ENGINEERING_HW3_REGISTERUI_H


#include "AbstractBoundary.h"
#include "../Member.h"

class RegisterControl;

class RegisterUI : public AbstractBoundary {
GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(RegisterControl)

public:
    void
    onRegisterRequest(MemberTypes type, string name, string securityNumber, string address, string id, string password);
};

#endif //SW_ENGINEERING_HW3_REGISTERUI_H
