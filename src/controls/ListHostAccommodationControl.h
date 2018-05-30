//
// Created by kimch on 2018-05-30.
//

#ifndef SW_ENGINEERING_HW3_HOSTACCOMMODATIONLISTCONTROL_H
#define SW_ENGINEERING_HW3_HOSTACCOMMODATIONLISTCONTROL_H


#include "../SingletonMacro.h"
#include "../boundaries/ListHostAccommodationUI.h"
#include "AbstractControl.h"
class ListHostAccommodationUI;

class ListHostAccommodationControl : public AbstractControl {
GENERATE_SINGLETON_DECLARE(ListHostAccommodationControl)
GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(ListHostAccommodationControl, ListHostAccommodationUI)

public:
    void listAccommodations();
};



#endif //SW_ENGINEERING_HW3_HOSTACCOMMODATIONLISTCONTROL_H
