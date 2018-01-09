/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月07日 星期二 19时26分29秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct lll{
    virtual void func(void) {
        return ;
    }
};


int func(void) {
    int a[25000000];
    return 1;
}

int main() {
    lll ii;
    int b = func();
    printf("%lu", sizeof(ii));
    return 0;
}
