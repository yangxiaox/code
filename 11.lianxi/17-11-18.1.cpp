/*************************************************************************
	> File Name: 17-11-18.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月18日 星期六 16时04分21秒
 ************************************************************************/

#include<iostream>
using namespace std;


int main() {
    int n = 1;
    for (int i = 1; i <= 100; ++i) {
        printf("%d", n >= i);
        if (i % 10 == 0) {
            n += 11;
            printf("\n");
        }
    }
    printf("\n\n");
    n = 1;
    for (int i = 1; i <= 100; ++i) {
        printf("%d", !(n >= i));
        if (i % 10 == 0) {
            n += 11;
            printf("\n");
        }
        
    }
    return 0;
}
