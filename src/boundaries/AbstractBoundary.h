//
// Created by kimch on 5/26/2018.
//

#ifndef SW_ENGINEERING_HW3_ABSTRACTBOUNDARY_H
#define SW_ENGINEERING_HW3_ABSTRACTBOUNDARY_H
#define GENERATE_GET_CONTROL(CLASS_NAME) public: CLASS_NAME* getCLASS_NAME() {return static_cast<CLASS_NAME *>(this->getControl());};

#include <string>
#include "../controls/AbstractControl.h"

using namespace std;

class AbstractControl;

class AbstractBoundary {
    friend class AbstractControl;

private:
    AbstractControl *control;
protected:
    AbstractBoundary();

    AbstractControl *getControl();

public:
    void print(const char *fmt, ...);

    void printLine(const char *fmt, ...);
};


#endif //SW_ENGINEERING_HW3_ABSTRACTBOUNDARY_H
