// 헤더 선언
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "MemberCollection.h"
#include "Member.h"
#include "OutputWriter.h"
#include "controls/SessionControl.h"
#include "Time.h"
#include "boundaries/RegisterUI.h"
#include "controls/RegisterControl.h"
// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
#define STR_INPUT_BUF 100

// 함수 선언
void doTask();

// void join();

void program_exit();

// 변수 선언
FILE *inputFp;

int main() {
    inputFp = fopen(INPUT_FILE_NAME, "r+");
    OutputWriter::getInstance()->open(OUTPUT_FILE_NAME);

    doTask();

    fclose(inputFp);
    OutputWriter::getInstance()->close();
    return 0;


}

void doTask() {
    // level 메뉴 파싱을 위한 구분을 위한 변수
    int menuLevel1 = 0, menuLevel2 = 0;
    int isProgramExit = 0;
    OutputWriter *outputWriter = OutputWriter::getInstance();
    while (!isProgramExit) {
        // 2 입력파일에서 메뉴 숫자 개를 읽기
        fscanf(inputFp, "%d %d ", &menuLevel1, &menuLevel2);
        outputWriter->write("%d.%d. ", menuLevel1, menuLevel2);
        // 메뉴 구분 및 해당 연산 수행
        switch (menuLevel1) {
            case 1: {
                //region TODO: 회원가입 & 탈퇴
                switch (menuLevel2) {
                    case 1: {
                        outputWriter->writeLine("회원가입");
                        RegisterUI *registerUI = RegisterControl::getInstance()->getRegisterUI();
                        char type[STR_INPUT_BUF],
                                name[STR_INPUT_BUF],
                                securityNumber[STR_INPUT_BUF],
                                address[STR_INPUT_BUF],
                                id[STR_INPUT_BUF],
                                password[STR_INPUT_BUF];

                        fscanf(inputFp, "%s %s %s %s %s %s", type, name, securityNumber, address, id, password);
                        MemberTypes typeEnum = (strcmp((const char *) type, "host") == 0 ? MemberTypes::Host
                                                                                         : MemberTypes::Guest);
                        registerUI->onRegisterRequest(typeEnum, string(name), string(securityNumber), string(address),
                                                      string(id), string(password));
                        break;
                    }
                    case 2: {
                        outputWriter->writeLine("회원탈퇴");
                        break;
                    }
                }
                break;
                //endregion
            }
            case 2: {
                //region TODO: 로그인 & 로그아웃
                switch (menuLevel2) {
                    case 1: {
                        //region 로그인
                        outputWriter->writeLine("로그인");
                        break;
                        //endregion
                    }
                    case 2: {
                        //region 로그아웃
                        outputWriter->writeLine("로그아웃");
                        break;
                        //endregion
                    }
                }
                break;
                //endregion
            }
            case 3: {
                //region TODO: 숙소 등록 & 조회
                switch (menuLevel2) {
                    case 1: {
                        //region 숙소 등록
                        outputWriter->writeLine("숙소 등록");
                        break;
                        //endregion
                    }
                    case 2: {
                        //region 등록 숙소 조회
                        outputWriter->writeLine("등록 숙소 조회");
                        break;
                        //endregion
                    }
                }
                break;
                //endregion
            }
            case 4: {
                //region TODO: 숙소 검색 & 예약 & Opaque & 예약 조회
                switch (menuLevel2) {
                    case 1: {
                        //region 숙소 검색
                        outputWriter->writeLine("숙소 검색");
                        break;
                        //endregion
                    }
                    case 2: {
                        //region 숙소 예약
                        outputWriter->writeLine("숙소 예약");
                        break;
                        //endregion
                    }
                    case 3: {
                        //region Opaque inventory 예약
                        outputWriter->writeLine("Opaque inventory 예약");
                        break;
                        //endregion
                    }
                    case 4: {
                        //region 예약정보 조회
                        outputWriter->writeLine("예약정보 조회");
                        break;
                        //endregion
                    }
                }
                break;
                //endregion
            }
            case 5: {
                //region 현재시간 설정
                switch (menuLevel2) {
                    case 1: {
                        outputWriter->writeLine("현재시간 설정");
                        char currentTime[STR_INPUT_BUF];
                        fscanf(inputFp, "%s\n", currentTime);
                        Time::setCurrentTime(currentTime);
                        outputWriter->writeLine("> %s", currentTime);
                        break;
                    }
                }
                break;
                //endregion
            }
            case 6: {
                //region 세션 변경 관련
                SessionUI *boundary = SessionControl::getInstance()->getSessionUI();
                switch (menuLevel2) {
                    case 1: {
                        //region Session 변경
                        outputWriter->writeLine("Session 변경");
                        char id[STR_INPUT_BUF];
                        fscanf(inputFp, "%s\n", id);
                        boundary->onChangeSession(id);
                        break;
                        //endregion
                    }
                    case 2: {
                        //region Guest session으로 변경
                        outputWriter->writeLine("Guest session으로 변경");
                        boundary->onChangeGuestSession();
                        break;
                        //endregion
                    }
                }
                break;
                //endregion
            }
            case 7: {
                //region 종료
                switch (menuLevel2) {
                    case 1: {
                        outputWriter->writeLine("종료");
                        program_exit();
                        isProgramExit = 1;
                        break;;
                    }
                }
                break;
                //endregion
            }
        }
        outputWriter->writeLine();
    }
}

/*
void join() {
    char user_type[MAX_STRING], name[MAX_STRING], SSN[MAX_STRING],
            address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
    // : , , , , ID, Password 입력 형식 사용자유형 이름 주민번호 주소 를 파일로부터 읽음
    fscanf(inputFp, "%s %s %s %s %s %s", user_type, name, SSN, address, ID, password);
    // 해당 기능 수행

    // 출력 형식
    // fprintf(out_fp, "1.1. \n");
    // 회원가입
    // fprintf(out_fp, "%s %s %s %s %s %s\n", user_type, name, SSN, address, ID, password);
}
*/
void program_exit() {

}
