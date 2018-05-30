//
// Created by 김창덕 on 2018-05-24.
//

#ifndef SW_ENGINEERING_HW3_MEMBER_H
#define SW_ENGINEERING_HW3_MEMBER_H

#include <string>

using namespace std;

/**
 * 회원 유형 Enumerable
 */
enum MemberTypes {
    HostMember, GuestMember
};

/**
 * 회원 정보에 관한 Class
 */
class Member {
private:
    MemberTypes type; // 회원 유형
    string name; // 회원 이름
    string securityNumber; // 회원 주민등록 번호
    string address; // 회원 주소
    string id; // 회원 ID
    string password; // 회원 패스워드
public:

    Member(MemberTypes type, string name, string securityNumber, string address, string id, string password);

    MemberTypes getType();

    string getName();

    string getAddress();

    string getID();

    /**
     * 패스워드 일치 여부 체크
     * @param password
     * @return 일치 여부
     */
    bool equalsPassword(string password);
};

#endif //SW_ENGINEERING_HW3_MEMBER_H
