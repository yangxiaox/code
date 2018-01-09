/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月07日 星期四 10时12分17秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
    virtual int func(void) = 0;
};

class B : public A{
};

class C : public B {
public:
    int func(void) override {
        return 2;

    }
};

int main() {
    C b;
    cout << b.func() << endl;
    return 0;
}
