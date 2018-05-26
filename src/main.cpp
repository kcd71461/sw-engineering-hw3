// 헤더 선언
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "MemberCollection.h"
#include "Member.h"
#include "OutputWriter.h"
#include "controls/SessionControl.h"
#include "Time.h"
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
                //region 회원가입 & 탈퇴
                switch (menuLevel2) {
                    case 1:
                        break;
                    case 2:
                        break;
                }
                break;
                //endregion
            }
            case 5: {
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
            }
            case 6: {
                //region 세션관련 명령
                SessionBoundary *boundary = SessionControl::getInstance()->getSessionBoundary();
                switch (menuLevel2) {
                    case 1: {
                        //region Session 변경
                        char id[STR_INPUT_BUF];
                        fscanf(inputFp, "%s\n", id);
                        boundary->onChangeSession(id);
                        break;
                        //endregion
                    }
                    case 2: {
                        //region Guest session으로 변경
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
