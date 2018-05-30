//
// Created by 김창덕 on 5/27/2018.
//

#ifndef SW_ENGINEERING_HW3_REGISTERCONTROL_H
#define SW_ENGINEERING_HW3_REGISTERCONTROL_H

#include "../SingletonMacro.h"
#include "../boundaries/RegisterUI.h"
#include "AbstractControl.h"
#include "../Member.h"
#include "../Host.h"
#include "../Guest.h"

class RegisterUI;

/**
 * 회원 가입 기능 Control Class.
 */
class RegisterControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(RegisterControl)

GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(RegisterControl, RegisterUI)

public:
    /**
     * 회원등록 요청을 수행
     * @param type
     * @param name
     * @param securityNumber
     * @param address
     * @param id
     * @param password
     */
    void registerMember(MemberTypes type, string name, string securityNumber, string address, string id,
                        string password);
};


#endif //SW_ENGINEERING_HW3_REGISTERCONTROL_H
