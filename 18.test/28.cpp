/*************************************************************************
	> File Name: 28.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月23日 星期二 15时38分57秒
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    int bb;
    static int func(); /*{
        A::aa = 1;
        return A::aa;
       // x = 1;
       // return x;
    }*/
private:
    A(); 
    ~A(); 
    static int aa;
};
int A::aa = 1;
int A::func() {
    A::aa = 1;
    return A::aa;
}

int main() {
    cout << A::func() <<endl;



    return 0;
}
