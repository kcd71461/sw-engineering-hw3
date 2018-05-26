//
// Created by kimch on 5/26/2018.
//

#ifndef SW_ENGINEERING_HW3_FILEWRITER_H
#define SW_ENGINEERING_HW3_FILEWRITER_H

#include <string>

using namespace std;

/**
 * File Writing 과 관련된 Class
 */
class OutputWriter {
private:
    FILE *filePointer = NULL;
    static OutputWriter *instance;

    OutputWriter();

public:
    static OutputWriter *getInstance();

    void open(string fileName);

    void close();

    void write(string fmt, ...);

    void writeLine(string fmt, ...);

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

    void writeLine();
};


#endif //SW_ENGINEERING_HW3_FILEWRITER_H
