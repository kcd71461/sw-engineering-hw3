//
// Created by kimch on 5/26/2018.
//

#include "AbstractControl.h"

AbstractControl::AbstractControl(AbstractBoundary *boundary) {
    this->boundary = boundary;
    this->boundary->control = this;
}

AbstractBoundary *AbstractControl::getBoundary() {
    return this->boundary;
}

AbstractControl::~AbstractControl() {
    delete (this->boundary);
}
