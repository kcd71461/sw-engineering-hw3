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
public:
    void sortbycost(); // 가격을 기준으로 컬렉션 오름차순 정렬
    int comparedate(string date1,string date2); // 두 날짜를 비교 해서 1(<) 0(=) -1(>)를 리턴
};



#endif //SW_ENGINEERING_HW3_ACCOMMODATIONCOLLECTION_H
