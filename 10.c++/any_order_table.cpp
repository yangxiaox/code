/*************************************************************************
	> File Name: any_order_table.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月06日 星期三 13时46分15秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <stdlib.h>
using namespace std;

#define OK 1
#define ERROR 0

template<typename T>
struct my_vector {
    int my_chuanzhang() {
        cout << "\033[31;4mout put chuanzhang 24.5 ability to run !\033[0m" << endl;
        string str1;
        double n;
        cin >> str1;
        if (str1 != "chuanzhang") {
            cout << "\033[31;4mYou go out!!!\033[0m" << endl;
            exit(0);
        }
        cin >> n;
        if (n < 24.5) {
            cout << "\033[31;4mYou go out!!!\033[0m" << endl;
            exit(0);
        } else if (n == 24.5) {
            cout << "\033[31;4mgood boy!\033[0m" << endl;    
        } else {
            cout << "\033[31;4mYoung, people have a future!\033[0m" << endl;    
        }
        return 0;
    }
    my_vector(int size) {
        //my_chuanzhang();
        this->data = new T[size];
        this->size = size;
        this->length = 0;
    }
    T& operator[](const int ind) {
        if (ind < 0 || ind >= this->length) {
            cout << "\033[30;4msegment fault !\033[0m" << endl;
            return this->nil;    
        } else {
            return this->data[ind];
        }
    }
    T& my_insert(const int ind) {
        if (ind < 0 || ind > this->length) {
            cout << "\033[30;4msegment fault !!!\033[0m" << endl;
            return this->nil;
        }
        for (int i = this->length; i > ind; --i) {
            this->data[i] = this->data[i - 1];
        }
        (this->length)++;
        return this->data[ind];
    }
    int my_search(const T value) {
        int flag = 0, k;
        for (int i = 0; i < this->length; ++i) {
            if (this->data[i] == value) {
                flag = 1;
                k = i;
                break;
            }
        }
        if (flag) {
            return k;
        } else {
            return -1;
        }
    }
    int my_delete(const int ind) {
        if (ind < 0 || ind >= this->length) {
            cout << "\033[30;4msegment fault !\033[0m]" << endl;
            return ERROR;
        }
        for (int i = ind; i < this->length - 1; ++i) {
            this->data[i] = this->data[i + 1];
        }
        (this->length)--;
        return OK;
    }
    int my_cout() {
        for (int i = 0; i < this->length; ++i) {
            if (i > 0) cout << " ";
            cout << "\033[30;1m" <<this->data[i] << "\033[0m";
        }
        cout << endl;
        return OK;
    }
    int my_sort() {
        sort(this->data, this->data + this->length);
        return OK;
    }
    T nil;
    T *data;
    int size;
    int length;
};

int main() {
    my_vector<int> a(100);
    a[0] = 3;
    a.my_insert(1) = 1;
    a.my_insert(0) = 10;
    a.my_insert(0) = 9;
    a.my_insert(0) = 7;
    a.my_insert(1) = 11;
    a.my_insert(2) = 30;
    cout << "\033[30;1m" << a[1] << "\033[0m" << endl;
    cout << "\033[30;1m10 coordinate is "<< a.my_search(10) << "\033[0m" << endl;
    a.my_delete(1);
    a.my_cout();
    a.my_sort();
    a.my_cout();
    return 0;
}
