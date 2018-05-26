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

    void *add(T *);

    void remove(int index);

    void remove(T *pItem);

    int getSize();
};

template<typename T>
T *Collection<T>::get(int index) {
    typename list<T *>::iterator iter = _list.begin();
    for (int i = 0; i < index; i++) {
        iter++;
    }
    return *iter;
}

template<typename T>
void *Collection<T>::add(T *item) {
    this->_list.push_back(item);
}

template<typename T>
void Collection<T>::remove(int index) {
    this->_list.remove(this->get(index));
}

template<typename T>
void Collection<T>::remove(T *pItem) {
    this->_list.remove(pItem);
}

template<typename T>
int Collection<T>::getSize() {
    return this->_list.size();
}


#endif //SW_ENGINEERING_HW3_COLLECTION_H
