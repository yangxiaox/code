/*************************************************************************
	> File Name: 7.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月21日 星期四 19时34分23秒
 ************************************************************************/

#include <iostream>
#include <utility>
using namespace std;

template<class T>
struct shared_ptr {
    shared_ptr() {
        obj = nullptr; 
        cnt = nullptr;
    }
    shared_ptr(T *obj) : obj(obj) {
        cnt = new int;
        *cnt = 1;
    }
    shared_ptr(shared_ptr<T> &a) {
        this->cnt = a.cnt;
        this->obj = a.obj;
        if (this->cnt) {
            *(this->cnt) += 1;
        }
    }
    ~shared_ptr() {
        if (cnt) {
            *cnt -= 1;
            if (*cnt == 0) {
                obj->~T();
                delete cnt;
            }
            obj = nullptr;
            cnt = nullptr;
        }
    }

    T *operator->() {
        return this->obj;
    }
    T *get() {
        return this->obj;
    }
    int user_count() {
        if (cnt) {
            return *cnt;
        }
        return 0;
    }
    int *cnt;
    T *obj;
};

struct A {
    A() { cout << "constructor A" << endl; }
    virtual ~ A() { cout << "des A" << endl; }
};

int main() {
    return 0;
}
