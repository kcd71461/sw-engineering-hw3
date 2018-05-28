//
// Created by kimch on 2018-05-24.
//

#ifndef SW_ENGINEERING_HW3_ACCOMMODATION_H
#define SW_ENGINEERING_HW3_ACCOMMODATION_H
#include <string>
using namespace std;

class Accommodation {
    string hostid;
    string name; 
    string address; 
    int cost; 
    string date; 
    int opaqueCost;

public:
    Accommodation(string hostid,string name, string address, int cost, string date, int opaqueCost) : hostid(hostid),name(name),
                 address(address),
                                                                                        cost(cost),
                                                                                        date(date),
                                                                                        opaqueCost(
                                                                                                opaqueCost) {}

    const string &getHostid() const {
        return hostid;
    }

    void setHostid(const string &hostid) {
        Accommodation::hostid = hostid;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Accommodation::name = name;
    }

    const string &getAddress() const {
        return address;
    }

    void setAddress(const string &address) {
        Accommodation::address = address;
    }

    int getCost() const {
        return cost;
    }

    void setCost(int cost) {
        Accommodation::cost = cost;
    }

    const string &getDate() const {
        return date;
    }

    void setDate(const string &date) {
        Accommodation::date = date;
    }

    int getOpaqueCost() const {
        return opaqueCost;
    }

    void setOpaqueCost(int opaqueCost) {
        Accommodation::opaqueCost = opaqueCost;
    }
};


#endif //SW_ENGINEERING_HW3_ACCOMMODATION_H
