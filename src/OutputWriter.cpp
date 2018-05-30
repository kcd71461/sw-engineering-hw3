//
// Created by 김창덕 on 5/26/2018.
//

#include <cstdarg>
#include "OutputWriter.h"
#include "SingletonMacro.h"

GENERATE_SINGLETON_IMPLEMENT(OutputWriter);

OutputWriter::OutputWriter() {}

void OutputWriter::open(string fileName) {
    this->filePointer = fopen(fileName.c_str(), "w+");
}

void OutputWriter::close() {
    fclose(this->filePointer);
}

void OutputWriter::write(string fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(this->filePointer, fmt.c_str(), args);
    va_end(args);
}

void OutputWriter::writeLine(string fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(this->filePointer, fmt.c_str(), args);
    va_end(args);
    fprintf(this->filePointer, "\n");
}

void OutputWriter::vwrite(const char *fmt, va_list list) {
    vfprintf(this->filePointer, fmt, list);
}

void OutputWriter::vwriteLine(const char *fmt, va_list list) {
    vfprintf(this->filePointer, fmt, list);
    fprintf(this->filePointer, "\n");
}

void OutputWriter::writeLine() {
    fprintf(this->filePointer, "\n");
}
