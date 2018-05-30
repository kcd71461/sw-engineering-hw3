//
// Created by 김창덕 on 5/26/2018.
//

#ifndef SW_ENGINEERING_HW3_FILEWRITER_H
#define SW_ENGINEERING_HW3_FILEWRITER_H

#include <string>
#include "SingletonMacro.h"
#include "boundaries/AbstractBoundary.h"

using namespace std;

/**
 * File Writing 과 관련된 Wrapper Class
 */
class OutputWriter {
    friend class AbstractBoundary;

GENERATE_SINGLETON_DECLARE(OutputWriter)

private:
    FILE *filePointer = NULL;

    OutputWriter();

    /**
     * va_list로 받아서 write
     * @param string
     * @param list
     */
    void vwrite(const char *string, va_list list);

    /**
     * va_list로 받아서 writeLine
     * @param string
     * @param list
     */
    void vwriteLine(const char *string, va_list list);

public:
    /**
     * 파일 스트림을 open
     * @param fileName
     */
    void open(string fileName);

    /**
     * 파일 스트림 close
     */
    void close();

    /**
     * 파일 출력
     * @param fmt 포맷
     * @param ... 서식문자 가변인자
     */
    void write(string fmt, ...);

    /**
     * 파일 출력 (개행 concat)
     * @param fmt 포맷
     * @param ... 서식문자 가변인자
     */
    void writeLine(string fmt, ...);

    /**
     * 파일에 개행문자 출력
     * @param fmt 포맷
     * @param ... 서식문자 가변인자
     */
    void writeLine();
};


#endif //SW_ENGINEERING_HW3_FILEWRITER_H
