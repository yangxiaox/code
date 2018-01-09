/*************************************************************************
	> File Name: 17-10-7.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月07日 星期六 19时52分43秒
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T> 
struct Test {
    template<typename U>
    U add(U a, U b) {
        return a + b;
    }
};




int main() {
    Test<int> t1;
    Test<double> t2;
    Test<int> t3;
    cout << t1.add(2, 3) << endl;
    cout << t2.add(2.2, 3.3) << endl;
    return 0;
}
