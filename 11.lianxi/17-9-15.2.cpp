/*************************************************************************
	> File Name: 17-9-15.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月15日 星期五 19时37分43秒
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int article_n(int n) {
    //if (n < 4) return n;
    int i;
    for (i = 1; i; ++i) {
        int x = n - pow(3, i) * i + pow(3, i - 1) * (i == 1 ? 0 : i);
        if (x <= 0) {
            break;
        }
        n = x;
    }
    //cout << i << " " << n << endl;
    int x = (n - 1) / i + 1;
    //cout << x <<endl;
    int c = pow(3, i - 1);
    int y = (c == 1 ? 0 : c) + x - 1;
    /*if (y == 1) y = 0;
    for (int j = 0; j < x - 1; ++j) {
        y += 1;
        int z = y;
        for (int k = 0; k < i - 1; ++k) {
            if (z % 10 == 3) {
                y = y + 7 * pow(10, k);
                z = z + 7;
            }
            z /= 10;
        }
    }*/
    //cout << y << endl;
    /*int z = n % i;
    if (z == 0) z = i;
    while (--z) {
        y /= 10;
    }*/
    //cout << y << endl;
    int z = (n - 1) % i;
    int index = y / pow(3, z);
    index = index % 3 + 1;
    return index;
}

int main() {
    int n;
    while (cin >> n) {
        cout << n << " is " << article_n(n) << endl;
    }
    return 0;
}
