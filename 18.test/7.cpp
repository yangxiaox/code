/*************************************************************************
	> File Name: 7.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月21日 星期四 19时34分23秒
 ************************************************************************/

//mutable

#include <iostream>
#include <utility>
using namespace std;

template<typename T>
struct shared_ptr {
    shared_ptr() {
        cout << "structure shared_ptr()" << endl;
        obj = nullptr; 
        cnt = nullptr;
    }
    shared_ptr(T *obj) : obj(obj) {
        cout << "structure shared_ptr T*" << endl;
        cnt = new int;
        *cnt = 1;
    }
    shared_ptr(shared_ptr<T> &a) {
        cout << "structure shared_ptr &" << endl;
        this->cnt = a.cnt;
        this->obj = a.obj;
        if (this->cnt) {
            *(this->cnt) += 1;
        }
    }
    shared_ptr(shared_ptr<T> &&a) {
        cout << "structure shared_ptr &&" << endl;
        this->obj = a.obj;
        this->cnt = a.cnt;
        a.obj = nullptr;
        a.cnt = nullptr;
    }

    template<class Q>
    shared_ptr(shared_ptr<Q> &&a) {
        cout << "structure shared_ptrQ &&" << endl;
        this->obj = a.obj;
        this->cnt = a.cnt;
        a.obj = nullptr;
        a.cnt = nullptr;
    }
    template<class Q>
    shared_ptr(Q *a) : obj(a) {
        cout << "structure shared_ptrQ *" << endl;
        cnt = new int;
        *cnt = 1;
    }

    ~shared_ptr() {
        cout << "~shared_ptr" << endl;
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
    
    template<typename Q>
    shared_ptr<T> operator=(shared_ptr<Q> &a) {
        cout << "shared_ptr = shared_ptr &" << endl;
        this->~shared_ptr();
        this = new shared_ptr<T>(a);
        return a;
    }
    template<typename Q>
    shared_ptr<T> operator=(shared_ptr<Q> &&a) {
        cout << "shared_ptr = shared_ptr &&" << endl;
        this->~shared_ptr();
        this = new shared_ptr<T>(forward(a));
        return a;
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
    virtual void sey() {
        cout << "hahahahahaha!" << endl;
    }
};

struct B : A {
    B() { cout << "constructor B" << endl; }
    ~ B() { cout << "des B" << endl; }
    virtual void sey() {
        cout << "heiheiheiheiheihei!" << endl;
    }
};

struct C{};

template< typename T, typename... Args >
shared_ptr<T> &&make_shared( Args&&... args ) {
    cout << "make_shared" << endl;
    return move(*(new shared_ptr<T>(forward<Args>(args)...)));
}

int main() {
    A *a = new A;
    //shared_ptr<A> p(new A);
    //make_shared<A>();
    shared_ptr<A> p1 = make_shared<A>(a);
    shared_ptr<A> p2 = p1;
    B *b = new B;
    shared_ptr<A> p3 = make_shared<B>(b);
    //C *c = new C;
    //shared_ptr<A> p4 = make_shared<C>(c);
    shared_ptr<A> p5(new B);
    p2->sey();
    p5->sey();
    int *x = new int(5);
    shared_ptr<int> p6 = make_shared<int>(x);
    shared_ptr<int> p7(new int(10));
    shared_ptr<A> p8(new A);
    shared_ptr<A> p9(new A);
    p8 = p9;
    return 0;
}
