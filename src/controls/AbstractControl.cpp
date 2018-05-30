//
// Created by 김창덕 on 5/26/2018.
//

#include "AbstractControl.h"
#include "../SessionCollection.h"

AbstractControl::AbstractControl(AbstractBoundary *boundary) {
    this->boundary = boundary;
    this->boundary->control = this;
}

AbstractBoundary *AbstractControl::getBoundary() {
    return this->boundary;
}



Member *AbstractControl::getCurrentMember() {
    return SessionCollection::getInstance()->getCurrentSession()->getMember();
}
