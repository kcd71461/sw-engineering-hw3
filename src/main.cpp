// 헤더 선언
#include <stdio.h>
#include <string.h>
#include "MemberCollection.h"
#include "Member.h"
// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();

void join();

void program_exit();

// 변수 선언
FILE *in_fp, *out_fp;

int main() {
    MemberCollection membercol;
    Member *pMember = new Member();
    membercol.add(pMember);

    FILE *in_fp = fopen(INPUT_FILE_NAME, "r+");
    FILE *out_fp = fopen(OUTPUT_FILE_NAME, "w+");

    doTask();

    return 0;
}

void doTask() {
    // level 메뉴 파싱을 위한 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit) {
        // 2 입력파일에서 메뉴 숫자 개를 읽기
        fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);

        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1) {
            case 1: {
                switch (menu_level_2) {
                    case 1: // "1.1. " 회원가입 메뉴 부분
                    {
                        // join() 함수에서 해당 기능 수행
                        join();

                        break;
                    }
                    case 2: {
                        break;
                    }
                }

                case 7: {
                    switch (menu_level_2) {
                        case 1: // "7.1. " 종료 메뉴 부분
                        {
                            program_exit();
                            is_program_exit = 1;
                            break;;
                        }
                    }
                }
            }
                return;
        }
    }
}

void join() {
    char user_type[MAX_STRING], name[MAX_STRING], SSN[MAX_STRING],
            address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
    // : , , , , ID, Password 입력 형식 사용자유형 이름 주민번호 주소 를 파일로부터 읽음
    fscanf(in_fp, "%s %s %s %s %s %s", user_type, name, SSN, address, ID, password);
    // 해당 기능 수행

    // 출력 형식
    fprintf(out_fp, "1.1. \n");
    // 회원가입
    fprintf(out_fp, "%s %s %s %s %s %s\n", user_type, name, SSN, address, ID, password);
}

void program_exit() {

}
