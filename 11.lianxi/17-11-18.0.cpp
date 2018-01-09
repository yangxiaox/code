/*************************************************************************
	> File Name: 17-11-18.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月18日 星期六 15时24分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n;
    char a[100];
    cin >> n;
    FILE *F;
    F = fopen("a.txt", "w+");
    printf("%d\n", sprintf(a,"%d", n));
    return 0;
}
