//
// Created by kimch on 5/26/2018.
//

#ifndef SW_ENGINEERING_HW3_BASECONTROL_H
#define SW_ENGINEERING_HW3_BASECONTROL_H

/**
 * get[BoundaryClassName] interface와 기본 생성자 선언부(.h) 코드 생성
 */
#define GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(CONTROL_CLASS_NAME, BOUNDARY_CLASS_NAME) public: BOUNDARY_CLASS_NAME *get##BOUNDARY_CLASS_NAME();\
private: CONTROL_CLASS_NAME();

/**
 * get[BoundaryClassName] interface와 기본 생성자 구현부(.cpp) 코드 생성
 */
#define GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(CONTROL_CLASS_NAME, BOUNDARY_CLASS_NAME) CONTROL_CLASS_NAME::CONTROL_CLASS_NAME() : AbstractControl(new BOUNDARY_CLASS_NAME) {} \
BOUNDARY_CLASS_NAME *CONTROL_CLASS_NAME::get##BOUNDARY_CLASS_NAME() { return static_cast<BOUNDARY_CLASS_NAME *>(this->getBoundary());};

#include "../boundaries/AbstractBoundary.h"

class AbstractBoundary;

class AbstractControl {
private:
    AbstractBoundary *boundary;
protected:
    AbstractControl(AbstractBoundary *boundary);

    ~AbstractControl();

public:
    AbstractBoundary *getBoundary();
};

#endif //SW_ENGINEERING_HW3_BASECONTROL_H
