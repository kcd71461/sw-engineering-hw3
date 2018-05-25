//
// Created by kimch on 5/25/2018.
//

#ifndef SW_ENGINEERING_HW3_COLLECTION_H
#define SW_ENGINEERING_HW3_COLLECTION_H


#include <list>

using namespace std;

template<typename T>
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

template<typename T>
T *Collection<T>::get(int index) {
    return nullptr;
}

template<typename T>
T *Collection<T>::add(T *) {
    return nullptr;
}

template<typename T>
void Collection<T>::remove(int index) {

}

template<typename T>
void Collection<T>::remove(T *pItem) {

}

template<typename T>
int Collection<T>::getSize() {
    return 0;
}



#endif //SW_ENGINEERING_HW3_COLLECTION_H
