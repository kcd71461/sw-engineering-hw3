
#include "Reservation.h"

Reservation::Reservation(const string &hostid, const string &name, const string &address, const string &date,
                         int cost) {

}

const std::__cxx11::basic_string<char> &Reservation::getHostid() const {
    return hostid;
}

void Reservation::setHostid(const std::__cxx11::basic_string<char> &hostid) {
    Reservation::hostid = hostid;
}

const std::__cxx11::basic_string<char> &Reservation::getName() const {
    return name;
}

void Reservation::setName(const std::__cxx11::basic_string<char> &name) {
    Reservation::name = name;
}

const std::__cxx11::basic_string<char> &Reservation::getAddress() const {
    return address;
}

void Reservation::setAddress(const std::__cxx11::basic_string<char> &address) {
    Reservation::address = address;
}

const std::__cxx11::basic_string<char> &Reservation::getDate() const {
    return date;
}

void Reservation::setDate(const std::__cxx11::basic_string<char> &date) {
    Reservation::date = date;
}

int Reservation::getCost() const {
    return cost;
}

void Reservation::setCost(int cost) {
    Reservation::cost = cost;
}
