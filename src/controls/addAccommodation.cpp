//
// Created by simjae on 18. 5. 27.
//

#include "addAccommodation.h"
#include "../AccommodationCollection.h"
#include "../Accommodation.h"
GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(addAccommodation,addAccommodationUI)
GENERATE_SINGLETON_IMPLEMENT(addAccommodation)

void addAccommodation::addNewAccommodation(string hostid,string name, string address, int cost, string date, int opaqueCost) {

        Accommodation* newAccommodation = new Accommodation(hostid,name,address,cost,date,opaqueCost);
        AccommodationCollection::getInstance()->add(newAccommodation);

}
// TODO: 필요한 Control 함수 구현
