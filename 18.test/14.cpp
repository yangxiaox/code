/*************************************************************************
	> File Name: 14.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月24日 星期日 17时07分27秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
    A() {}
    ~A() {}
    void operator()(int i) {
        cout << "aaa " << i << endl;
        return ;
    }
};

int main() {
    A *a = new A;
    a->operator()(1);
    
    return 0;
}
