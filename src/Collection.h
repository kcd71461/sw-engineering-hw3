//
// Created by kimch on 2018-05-24.
//

#ifndef SW_ENGINEERING_HW3_COLLECTION_H
#define SW_ENGINEERING_HW3_COLLECTION_H

#include <list>

using namespace std;

template<class T>
class Collection {
protected:
    list<T *> _list;
public :
    T *get(int index);
    T *add(T *);
    void remove(int index);
    void remove(T *pItem);
    int getSize();
};

#endif //SW_ENGINEERING_HW3_COLLECTION_H
