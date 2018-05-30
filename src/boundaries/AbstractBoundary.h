//
// Created by kimch on 5/26/2018.
//

#ifndef SW_ENGINEERING_HW3_ABSTRACTBOUNDARY_H
#define SW_ENGINEERING_HW3_ABSTRACTBOUNDARY_H

/**
 * get[ControlClassName] interface 선언부(.h) 코드 생성
 */
#define GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(CONTROL_CLASS_NAME) public: CONTROL_CLASS_NAME* get##CONTROL_CLASS_NAME();

/**
 * get[ControlClassName] interface 구현부(.cpp) 코드 생성
 */
#define GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(BOUNDARY_CLASS_NAME, CONTROL_CLASS_NAME) CONTROL_CLASS_NAME * BOUNDARY_CLASS_NAME::get##CONTROL_CLASS_NAME() {\
return reinterpret_cast<CONTROL_CLASS_NAME *>(this->getControl());\
}

#include <string>
#include "../controls/AbstractControl.h"

using namespace std;

class AbstractControl;

/**
 * Boundary Class Abstraction
 */
class AbstractBoundary {
    friend class AbstractControl;

private:
    AbstractControl *control;
protected:
    AbstractBoundary();

    /**
     * 매칭 Control 반환하는 함수
     */
    AbstractControl *getControl();

public:
    /**
     * 파일 출력
     * @param fmt 포맷
     * @param ... 서식문자인자
     */
    virtual void print(const char *fmt, ...);

    /**
     * 파일 출력(개행)
     * @param fmt 포맷
     * @param ... 서식문자인자
     */
    virtual void printLine(const char *fmt, ...);
};


#endif //SW_ENGINEERING_HW3_ABSTRACTBOUNDARY_H
