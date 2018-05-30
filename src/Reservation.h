//
// Created by 김창덕 on 2018-05-24.
//

#ifndef SW_ENGINEERING_HW3_RESERVATION_H
#define SW_ENGINEERING_HW3_RESERVATION_H

#include <string>

using namespace std;

/**
 * 예약 정보와 관련된 정보 Class.
 */
class Reservation {
private:
    string hostid; // 숙소 HostName
    string guesid; // 예약 guest id
    string name; // 숙소명
    string address; // 주소
    string date; // 날짜
    int cost; // 예약 가격
public:
    /**
     * Reservation 생성자
     * @param hostid
     * @param guestid
     * @param name
     * @param address
     * @param date
     * @param cost
     */
    Reservation(const string &hostid, const string &guestid,const string &name, const string &address, const string &date, int cost);

    const string &getGuestID() const;

    void setGuesid(const string &guesid);

    const string &getHostID() const;

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
