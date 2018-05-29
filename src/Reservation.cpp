
#include "Reservation.h"


const std::string &Reservation::getHostid() const {
    return hostid;
}

void Reservation::setHostid(const std::string &hostid) {
    Reservation::hostid = hostid;
}

const std::string &Reservation::getName() const {
    return name;
}

void Reservation::setName(const std::string &name) {
    Reservation::name = name;
}

const std::string &Reservation::getAddress() const {
    return address;
}

void Reservation::setAddress(const std::string &address) {
    Reservation::address = address;
}

const std::string &Reservation::getDate() const {
    return date;
}

void Reservation::setDate(const std::string &date) {
    Reservation::date = date;
}

int Reservation::getCost() const {
    return cost;
}

void Reservation::setCost(int cost) {
    Reservation::cost = cost;
}

const string &Reservation::getGuesid() const {
    return guesid;
}

void Reservation::setGuesid(const string &guesid) {
    Reservation::guesid = guesid;
}


Reservation::Reservation(const string &hostid, const string &guesid, const string &name, const string &address,
                         const string &date, int cost) : hostid(hostid), guesid(guesid), name(name), address(address),
                                                         date(date), cost(cost) {}
