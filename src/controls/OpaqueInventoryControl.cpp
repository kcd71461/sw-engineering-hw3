//
// Created by 권영진 on 2018. 5. 28..
//

#include "OpaqueInventoryControl.h"
#include "../AccommodationCollection.h"


GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(OpaqueInventoryControl,OpaqueInventoryUI)
GENERATE_SINGLETON_IMPLEMENT(OpaqueInventoryControl)

void OpaqueInventoryControl::tryOpaqueInventoryReservation(string address, string date, int opaqueCost) {
    AccommodationCollection *accommodations = AccommodationCollection::getInstance();

    for(int i=0; i<accommodations->getSize(); i++){
        Accommodation *accommodation = accommodations->get(i);

        if(accommodation->getAddress()==address && accommodation->getDate()==date && accommodation->getOpaqueCost()!=0){
            //if(이미저장된accommodation->getOpaqueCost()>)
        }
        //else

    }




}
// TODO: 필요한 Control 함수 구현
