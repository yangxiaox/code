/*************************************************************************
	> File Name: 17-9-20.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月20日 星期三 18时51分46秒
 ************************************************************************/

#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_N = 10000000;

double rand_point() {
    return ((rand() % 2000000) - 1000000.0) / 1000000.0;
}



int main() {
    srand(time(0));
    int n1 = 0, n2 = 0;
    for (int i = 0; i < MAX_N; ++i) {
        double x1, x2;
        x1 = rand_point();
        x2 = rand_point();
        if (x1 * x1 + x2 * x2 > 1.0) {
            n2++;
        } else {
            n1++;
        }
    }
    cout << fixed << setprecision(6) << "PI : " << 4.0 * n1 / (n1 + n2) << endl;
    return 0;
}

