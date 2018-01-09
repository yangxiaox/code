/*************************************************************************
	> File Name: 17-10-20.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月20日 星期五 10时11分46秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

class Accet {
private :
    int *data;
    int length;
public :
    Accet(int len = 10) : length(len) {
        this->data = new int[len];
        //this->data = (int *)malloc(sizeof(int) * len);
    }
    Accet(const Accet& aa) : length(aa.length) {
        //this->data = (int *)malloc(sizeof(int) * this->length);//new int[this->length];
        this->data = new int[this->length];
        memcpy(this->data, aa.data, this->length);
    }
    ~Accet() {
        //free(this->data);
        delete[] this->data;
    }
};

class Testt {
private :
    Accet *arr;
    int length;
    int size;
public :
    Testt(int len = 10) : size(len), length(0) {
        this->arr = new Accet[this->size];

    }
    Testt(const Testt& tt) : size(tt.size), length(tt.length) {
        this->arr = new Accet[this->size];
        memcpy(this->arr, tt.arr, this->length);
        /*this->arr = (Accet *)malloc(sizeof(Accet) * this->size);
        for (int i = 0; i < this->length; ++i) {
            new(this->arr + i)Accet(*(tt.arr + i));
        }*/
    }
    ~Testt() {
        for (int i = 0; i < this->length; ++i) {
            this->arr[i].~Accet();
        }
        delete[] this->arr;
        this->length = 0;
        this->size = 0;
        //this->arr = nullptr;
    }
    void Add(const Accet& aa) {
        if (this->length >= this->size) {
            return ;
        }

        new(this->arr + this->length)Accet(aa);
        (this->length)++;
        return ;
    }
};

Accet func() {
    Accet a0;
    return a0;
}

int main() {
    Accet a1;
    Testt t1;
                    cout << "1" << endl;
    t1.Add(func());
    //Accet a2;
   //                 cout << "2" << endl;
    //t1.Add(a1);
   //                 cout << "3" << endl;
    t1.Add(func());
                    cout << "4" << endl;
    t1.Add(func());
                    cout << "5" << endl;
    t1.Add(func());
                    cout << "6" << endl;
    Testt t2(t1);
                    cout << "ok!" << endl;
    //t2.~Testt();
    return 0;
}
