/*************************************************************************
	> File Name: 17-9-14.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月14日 星期四 18时14分22秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
struct my_less {
    bool operator()(const T &a, const T &b) {
        return a < b;
    }
};

class Point {
public:
    Point(int x, int y) : __x(x), __y(y) {}
    void out() {
        cout << "Point(" << this->__x << ", " << this->__y << ")" << endl;
    }
    bool operator<(const Point &a) const {
        return this->__x < a.__x;
    }
private:
    int __x, __y;
};

int main() {
    vector<Point> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        arr.push_back(Point(x, y));
    }
    sort(arr.begin(), arr.end(), my_less<Point>());
    for (auto &i : arr) {
        i.out();
    }
    return 0;
}
