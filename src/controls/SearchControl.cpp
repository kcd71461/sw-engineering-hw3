//
// Created by simjae on 18. 5. 27.
//

#include "SearchControl.h"
#include "../boundaries/SearchUI.h"
#include "../AccommodationCollection.h"
#include "../Accommodation.h"
#include "../Reservation.h"
#include "../ReservationCollection.h"
#include <string>

GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(SearchControl, SearchUI)
GENERATE_SINGLETON_IMPLEMENT(SearchControl)

string SearchControl::searchAccommodations(string address, string date) {
    AccommodationCollection *accommodations = AccommodationCollection::getInstance();
    string returnvalue;
    accommodations->sortbycost(); // 가격을 기준으로 오름차순 정렬
    for(int i=0; i<accommodations->getSize(); i++ ){
        Accommodation* accommo = accommodations->get(i);
        if(accommo->getAddress() == address && accommo->getDate() == date){
            returnvalue += accommo->getHostid()+" "+accommo->getName()+" "+accommo->getAddress()+" "+to_string(accommo->getCost())+"\n";
        }
    }
    return returnvalue;
    // this->getSearchUI()->printLine()

}

string SearchControl::addReservation(string hostid, string guestid,string accommoname) {
    AccommodationCollection* accommodationCollection = AccommodationCollection::getInstance();
    string name,address,date,returnvalue;
    int cost;
    Reservation* reservation;
    for(int i=0; i<accommodationCollection->getSize(); i++){
        Accommodation* accommodation = accommodationCollection->get(i);
        if(accommodation->getName() == accommoname){
            name = accommodation->getName();
            address = accommodation->getAddress();
            date = accommodation->getDate();
            cost = accommodation->getCost();

            reservation = new Reservation(hostid,guestid,name,address,date,cost);
            ReservationCollection::getInstance()->add(reservation);
            returnvalue += hostid+" "+name+" "+address+" "+date+" "+to_string(cost)+"\n";

        }
    }
    return returnvalue;
}

string SearchControl::getAllAccommodations() {
    string returnvalue;
    //등록된 숙소 조회(이용날짜가 빠른순으로 출력)
    // 3 2 커맨드 입력시  {숙소이름 숙소주소 가격 날짜 예약여부 opaque inventory 가격}* 출력
    /*
     *  3.2. 등록 숙소 조회
        > room1 seoul 100000 2018:05:20 X 70000
        > room2 seoul 100000 2018:05:21 X 70000
     * */
    AccommodationCollection* accommodationCollection = AccommodationCollection::getInstance();
    accommodationCollection->sortbydate();
    ReservationCollection* reservationCollection = ReservationCollection::getInstance();
    for(int i=0; i<accommodationCollection->getSize(); i++){
        Accommodation* accommodation = accommodationCollection->get(i);
        bool check = false;
        for(int j=0; j<reservationCollection->getSize(); j++){
            Reservation* reservation = reservationCollection->get(j);
            if(accommodation->getName() == reservation->getName())
                check = true; //예약 컬렉션에 있는 모든 예약에 대해 현재 숙소가 있는지를 검사
        }
        if(check)
            returnvalue += accommodation->getName() + " " + accommodation->getAddress() + " " + to_string(accommodation->getCost()) + " " + accommodation->getDate()+" "+"O"+" "+to_string(accommodation->getOpaqueCost()) +"\n";
        else
            returnvalue += accommodation->getName() + " " + accommodation->getAddress() + " " + to_string(accommodation->getCost()) + " " + accommodation->getDate()+" "+"X"+" "+to_string(accommodation->getOpaqueCost()) +"\n";

    }

    return returnvalue;
}

// TODO: 필요한 Control 함수 구현
