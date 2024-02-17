#ifndef __MYVEC_H__
#define __MYVEC_H__

#define BEGIN_NS_MYVEC namespace myvec {
#define END_NS_MYVEC }

BEGIN_NS_MYVEC

class MyVector {
private:
    int *ptr;
    unsigned int _size;
    unsigned int capacity; // 과제 2에서만 사용
public:
    void push_back(int value);
    void pop_back();
    void clear();
    void resize(unsigned int n);
    unsigned int size();
    bool empty();
    int get(int i);

    // 추가 함수 선언이 필요하면 아래에 작성
};

END_NS_MYVEC

#endif
