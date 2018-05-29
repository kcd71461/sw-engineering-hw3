//
// Created by simjae on 18. 5. 27.
//

#include <cstring>
#include "AccommodationCollection.h"
#include "SingletonMacro.h"
using namespace std;
GENERATE_SINGLETON_IMPLEMENT(AccommodationCollection)

AccommodationCollection::AccommodationCollection() {
}

void AccommodationCollection::sortbycost() {
    AccommodationCollection* accommodationCollection = AccommodationCollection::getInstance();
    for(int i=0; i<accommodationCollection->getSize()-1; i++){ //selection sort
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
        accommodationCollection->set(index,accommodationCollection->get(i));
        accommodationCollection->set(i,tmp);
    }

}

int AccommodationCollection::comparedate(string date1, string date2) {
    //날짜 포맷 2018:05:20
    return strcmp(date1.c_str(),date2.c_str());
}
