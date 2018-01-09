/*************************************************************************
	> File Name: 17-9-17.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月17日 星期日 08时38分18秒
 ************************************************************************/

#include<iostream>
using namespace std;

//#define Print(a) (cout << a << endl)



template<typename T>
void Print(const T &a) {
    cout << a << endl;
};

template<typename T, typename Y>
struct Point {
    T a;
    Y b;
};

/*#define Point(T) \
    struct Point##_##T { \
        T a, b; \
    };

Point(int)
Point(double)
*/
int main() {
    Point<int, double> p1 = {1, 2.5};
    Print(p1.a);
    Print(p1.b);
    int a = 123;
    Print(a);
    double b = 456.7;
    Print(b);
    char c = 'Z';
    Print(c);
    return 0;
}
