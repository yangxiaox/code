/*************************************************************************
	> File Name: 10.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月24日 星期日 08时43分25秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;

template<class T>
class shared_ptr {
public:
    shared_ptr() : obj(nullptr), cnt(nullptr) {}
    shared_ptr(const shared_ptr<T> &b) {
        if (this == &b) return ;
        this->obj = b.obj;
        this->cnt = b.cnt;
        if (this->cnt != nullptr) {
            this->incerase();
        }
    }
    shared_ptr(T *obj) {
        this->obj = obj;
        if (this->obj) {
            this->initCnt();
            cout << "cnt p : " << this->cnt << endl;
            this->setCnt(1);
        }
    }
    ~shared_ptr() {
        cout << "!!" << endl;
        this->judgedelete();
        cout << "??" << endl;
    }

    T *operator->() { return this->obj; }
    template<typename U> 
    shared_ptr<T> &operator=(const shared_ptr<U> &b) {
        this->judgedelete();
        this->obj = b.obj;
        this->cnt = b.cnt;
        if (this->cnt != nullptr) {
            this->incerase();
        }
        return *this;
    }

    template<class U> friend struct shared_ptr;

private:
    void initCnt() { this->cnt = new int;}
    void setCnt(int x) { (*(this->cnt)) = x; }
    void incerase() { (*(this->cnt))++; }
    void descerase() { (*(this->cnt))--; }
    bool iszearo() { return (*(this->cnt)) == 0; }
    void judgedelete() {
        if (this->obj != nullptr) {
            this->descerase();
            if (this->iszearo()) {
                cout << "delete cnt p : " << this->cnt << endl;
                delete (this->obj);
                delete (this->cnt);
            }
        }
        this->obj = nullptr;
        this->cnt = nullptr;
    }
    T *obj;
    int *cnt;
};

class A {
public:
    A() {}
    virtual ~A() {}
    virtual void say() { cout << "I am A" << endl; return ; }
};

class B : public A{
public:
    B() {}
    virtual ~B() {}
    virtual void say() { cout << "I am B" << endl; return ; }
};

int main() {
    int *aa = new int;
    delete aa;
    A *a = new A;
    shared_ptr<A> p(a);
    p->say();
    return 0;
}
