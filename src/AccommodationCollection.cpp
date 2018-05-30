//
// Created by 김창덕 on 18. 5. 27.
//

#include <cstring>
#include "AccommodationCollection.h"
#include "SingletonMacro.h"
using namespace std;
GENERATE_SINGLETON_IMPLEMENT(AccommodationCollection)

AccommodationCollection::AccommodationCollection() {
}

void AccommodationCollection::sortbycost() { // 숙소컬렉션의 숙소들을 cost를 기준으로 오름차순 정렳 하는 함수.
    AccommodationCollection* accommodationCollection = AccommodationCollection::getInstance();
    for(int i=0; i<accommodationCollection->getSize()-1; i++){ //selection sort 빅오는 O(n^2)
        int MIN = accommodationCollection->get(i)->getCost();
        int index = i;
        for(int j=i+1; j<accommodationCollection->getSize(); j++){
            if(MIN > accommodationCollection->get(j)->getCost()) {
                MIN = accommodationCollection->get(j)->getCost();
                index = j;
            }
        }
        //arr[index]와 arr[i] swap
        Accommodation* tmp = accommodationCollection->get(index);
        accommodationCollection->set(index,accommodationCollection->get(i)); //숙소 컬렉션의 index번째 item을 두번째 인자에 전달된 숙소로 덮어 씌우는 함수.
        accommodationCollection->set(i,tmp);
    }

}

void AccommodationCollection::sortByDate() { // 숙소 컬렉션의 숙소들을 date를 기준으로 오름차순 정렬 하는 함수.
    AccommodationCollection* accommodationCollection = AccommodationCollection::getInstance();
    for(int i=0; i<accommodationCollection->getSize()-1; i++){ //selection sort
        string mindate = accommodationCollection->get(i)->getDate();
        int index=i;
        for(int j=i+1; j<accommodationCollection->getSize(); j++){
            Accommodation* accommodation = accommodationCollection->get(j);
            string curdate = accommodation->getDate();
            if(mindate.compare(curdate) > 0){
                mindate = curdate; //deep copy
                index = j;
            }

        }

        //arr[index]와 arr[i]를 swap
        Accommodation* tmp = accommodationCollection->get(index);
        accommodationCollection->set(index,accommodationCollection->get(i));
        accommodationCollection->set(i,tmp);

    }
}
