//
// Created by kimch on 5/26/2018.
//

#include <cstdarg>
#include "AbstractBoundary.h"
#include "../OutputWriter.h"

void AbstractBoundary::print(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    OutputWriter::getInstance()->vwrite(fmt, args);
    va_end(args);
}

void AbstractBoundary::printLine(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    OutputWriter::getInstance()->vwriteLine(fmt, args);
    va_end(args);
}

AbstractBoundary::AbstractBoundary() {}

AbstractControl *AbstractBoundary::getControl() {
    return this->control;
}
