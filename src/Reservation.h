//
// Created by kimch on 2018-05-24.
//

#ifndef SW_ENGINEERING_HW3_RESERVATION_H
#define SW_ENGINEERING_HW3_RESERVATION_H

#include <string>

using namespace std;

class Reservation {
private:
    string hostid;
    string name;
    string address;
    string date;
    int cost;
public:
    Reservation(const string &hostid, const string &name, const string &address, const string &date, int cost);

    const string &getHostid() const;

    void setHostid(const string &hostid);

    const string &getName() const;

    void setName(const string &name);

    const string &getAddress() const;

    void setAddress(const string &address);

    const string &getDate() const;

    void setDate(const string &date);

    int getCost() const;

    void setCost(int cost);
};

#endif //SW_ENGINEERING_HW3_MEMBER_H
