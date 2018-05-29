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

void AccommodationCollection::sortbydate() {
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
