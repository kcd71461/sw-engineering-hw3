//
// Created by 심재철 on 18. 5. 27.
//

#include "addAccommodation.h"
#include "../AccommodationCollection.h"
#include "../Accommodation.h"
GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(addAccommodation, addAccommodationUI)
GENERATE_SINGLETON_IMPLEMENT(addAccommodation)

void addAccommodation::addNewAccommodation(string hostid, string name, string address, int cost, string date, int opaqueCost) {

    Accommodation *newAccommodation = new Accommodation(hostid, name, address, cost, date, opaqueCost);
    AccommodationCollection::getInstance()->add(newAccommodation);//숙소 컬렉션에 새로운 숙소를 추가함.
    this->getaddAccommodationUI()->printLine("> %s %s %d %s %d", name.c_str(), address.c_str(), cost, date.c_str(), opaqueCost);//추가된 새로운 숙소에 대한 정보를 출력.
}
