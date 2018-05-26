//
// Created by kimch on 5/26/2018.
//

#ifndef SW_ENGINEERING_HW3_BASECONTROL_H
#define SW_ENGINEERING_HW3_BASECONTROL_H

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
