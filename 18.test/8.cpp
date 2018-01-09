/*************************************************************************
	> File Name: 8.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月21日 星期四 20时22分13秒
 ************************************************************************/

#include <iostream>
#include <memory>
using namespace std;

//#define make_shared<a>() make_shared<#a>()

struct A{
    A() {}
    ~A() {}
};

struct B : A{

};

struct C{};

//template< class T, class... Args >
//shared_ptr<T> make_shared( Args&&... args ) {
//    return new shared_ptr<T>(forward<Args>(args)...);
//}

//template<typename T> 
//shared_ptr<T> make_shared<>

int main() {
    A *a = new A;
    A *b = new A;
    shared_ptr<A> p1(a);
    shared_ptr<A> p2(new B);
    shared_ptr<A> p3(new C);
    //shared_ptr<A> p2(b);
    //shared_ptr<A> p3 = p2;
    //p2 = p1;
    return 0;
}
