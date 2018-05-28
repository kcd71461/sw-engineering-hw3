//
// Created by kimch on 2018-05-24.
//

#ifndef SW_ENGINEERING_HW3_ACCOMMODATIONCOLLECTION_H
#define SW_ENGINEERING_HW3_ACCOMMODATIONCOLLECTION_H

#include "SingletonMacro.h"
#include "Accommodation.h"
#include "Collection.h"

using namespace std;

class AccommodationCollection : public Collection<Accommodation> {
    GENERATE_SINGLETON_DECLARE(AccommodationCollection);
private:
    AccommodationCollection();
};



#endif //SW_ENGINEERING_HW3_ACCOMMODATIONCOLLECTION_H
