
#include "Reservation.h"

Reservation::Reservation(const string &hostid, const string &name, const string &address, const string &date,
                         int cost) {

}

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
