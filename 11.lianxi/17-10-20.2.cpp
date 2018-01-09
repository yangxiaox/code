/*************************************************************************
	> File Name: 17-10-20.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月20日 星期五 19时52分25秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MAX_N 10

struct A {
    int *arr;
    A() {
        arr = (int *)malloc(sizeof(int) * MAX_N);
    }
    A(const A& a) {
        arr = (int *)malloc(sizeof(int) * MAX_N);
        memcpy(this->arr, a.arr, sizeof(int) * MAX_N);
        cout << "A copy constructor" << endl;
    }
    A(A&& a) : arr{ a.arr } {
        a.arr = nullptr;
        cout << "A move constructor" << endl;
    }
    ~A() {

        cout << endl << "A delete : " << arr << endl;
        free(arr);
    }
};

template<typename T>
class Vector {
public:
    T *items;
    int count;
    Vector() : count(0), items(nullptr) {
        cout << "V constructor" << endl;
    }
    Vector(const Vector& vector) : count{vector.count} {
        items = static_cast<T*>(malloc(sizeof(T) * count));
        memcpy(items, vector.items, sizeof(T) * count);
        cout << "v's copy" << endl;
    }
    Vector(Vector&& vector) : count{vector.count}, items{vector.items} {
        vector.items = nullptr;
        cout << "v's move" << endl;
    }
    void add(const T &item) {
        items = (T *)realloc(this->items, sizeof(T) * (this->count + 1));
        new(items + this->count) T(item);
        this->count++;
        cout << "add something" << endl;
    }
    ~Vector() {
        for (int i = 0; i < this->count; ++i) {
            this->items[i].~A();
            cout << "free" << i << " ";
        }
        free(this->items);
        //this->items = nullptr;
        cout << "delete done" << endl;
    }
};

Vector<A> v;
int func1() {
    v.add(A{});
    v.add(A{});
    v.add(A{});
    Vector<A> temp(v);
    return 0;

}

int main() {
    func1();
    A a{v.items[0]};
    for (int i = 0; i < 10; i++) {
        v.items[2].arr[i] = i + 1;
        a.arr[i] = 0;
    }
    for (int i = 0; i < 10; i++) {
        cout << v.items[2].arr[i] << ", " << a.arr[i] << endl;
    }
    return 0;
}
