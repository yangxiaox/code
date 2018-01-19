/*************************************************************************
	> File Name: 21.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月10日 星期三 11时07分25秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define MIN(a, b) ({\
                   __typeof(a) __##tempa = (a);\
                   __typeof(b) __##tempb = (b);\
                    __##tempa <= __##tempb ? __##tempa : __##tempb;\
                   })

#define iMIN(a, b) ((a) <= (b) ? (a) : (b))

int main() {
    int a = 3;
    int b = 2;
    cout << MIN(a, b++) << endl;
    cout << b << endl;
    return 0;
}
