//
// Created by kimch on 2018-05-28.
//

#include "Host.h"

AccommodationCollection *Host::getAccommodations() {
    AccommodationCollection *accomodations = AccommodationCollection::getInstance();
    // AccommodationCollection *result = new AccommodationCollection();
    for (int i = 0; i < accomodations->getSize(); i++) {
        
    }
}

Host::Host(const string &name, const string &securityNumber, const string &address, const string &id, const string &password) : Member(MemberTypes::HostMember, name, securityNumber, address, id, password) {}
