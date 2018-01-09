/*************************************************************************
	> File Name: arbitrary_array.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月06日 星期三 13时33分14秒
 ************************************************************************/

#include <iostream>
#include <string>

template<typename T>
struct array {
    array(int size) {
        this->data = new T[size];
        this->size = size;       
    }
    T& operator[](const int ind) {
        if (ind < 0 || ind >= this->size) {
            std::cout << "segment fault ! but I am xiaoqiang !" << std::endl;
            return this->nil;    
        } else {   
            return this->data[ind];
        }
    }
    void array_filp() {
        for (int i = 0; i < (this->size) / 2; ++i) {
            this->data[i] ^= this->data[this->size - i - 1];
            this->data[this->size - i - 1] ^= this->data[i];
            this->data[i] ^= this->data[this->size - i - 1];
        }
        return ;
    }
    T nil;
    T *data;
    int size;
};
  
int main() {/*
    array<int> a(100);
    array<double> b(100);
    array<std::string> c(100);
    a[65] = 123;
    b[65] = 7.666;
    c[65] = "hello world";
    std::cout << a[65] << " " << b[65] << " " << c[65] << std::endl;
    a[105] = 6754;
    b[103] = 453;*/
    array<int> a(10);
    a[7] = 2;
    a[8] = 1;
    a[1] = 8;
    a[3] = 6;
    a[10] = 22;
    a.array_filp();
    for (int i = 0; i < 10; ++i) {
        std::cout << a[i] << " ";
    }
    return 0;
}
