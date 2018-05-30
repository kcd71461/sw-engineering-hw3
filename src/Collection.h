//
// Created by 김창덕 on 5/25/2018.
//

#ifndef SW_ENGINEERING_HW3_COLLECTION_H
#define SW_ENGINEERING_HW3_COLLECTION_H


#include <list>

using namespace std;

/**
 * List Wrapper인 Collection Template Class.
 * @tparam T
 */
template<typename T>
class Collection {
protected:
    list<T *> _list;
public :
    /**
     * 해당 index의 item를 반환
     * @param index
     * @return item
     */
    T *get(int index);

    /**
     * collection에 item을 추가
     * @return
     */
    void *add(T *);
    /**
     * 해당 index에 새로운 멤버 삽입 또는 교체
     * @param index
     */
    int set(int index,T* item);
    /**
     * 해당 index의 item을 collection에서 삭제
     * @param 성공 여부
     */
    void remove(int index);

    /**
     * 해당 item을 collection에서 삭제
     * @param pItem
     */
    void remove(T *pItem);

    /**
     * collection의 item 갯수 반환
     * @return item 갯수
     */
    int getSize();

    /**
     * collection에 Item 포함 여부
     * @param pItem
     * @return 포함 여부
     */
    bool exists(T *pItem);
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

int Collection<T>::set(int index,T* item) {
    if(index >= getSize()) return -1; // 컬렉션의 크기를 초과한 곳에 삽입 하려고 하면 set 실패
    typename list<T *>::iterator iter = _list.begin();
    for(int i=0; i< index; i++){
        iter++;
    }
    *iter = item;
    return 1; //set 성공
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

template<typename T>
bool Collection<T>::exists(T *pItem) {
    int size = this->getSize();
    for (int i = 0; i < size; i++) {
        if (this->get(i) == pItem) {
            return true;
        }
    }
    return false;
}


#endif //SW_ENGINEERING_HW3_COLLECTION_H
