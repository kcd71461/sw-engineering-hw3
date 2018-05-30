//
// Created by 변상혁 on 18. 5. 27.
//

#include "addAccommodationUI.h"
#include "../controls/addAccommodation.h"

GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(addAccommodationUI,addAccommodationControl)

void addAccommodationUI::createAccommodation(string hostid,string name, string address, int cost, string date, int opaqueCost) {

       addAccommodation::getInstance()->addNewAccommodation(hostid,name,address,cost,date,opaqueCost);
}