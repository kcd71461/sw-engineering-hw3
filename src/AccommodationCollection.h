//
// Created by 김창덕 on 2018-05-24.
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
public:
    void sortbycost(); // 가격을 기준으로 컬렉션 오름차순 정렬
    void sortByDate(); // 날짜를 기준으로 컬렉션 오름차순 정렬
};



#endif //SW_ENGINEERING_HW3_ACCOMMODATIONCOLLECTION_H
