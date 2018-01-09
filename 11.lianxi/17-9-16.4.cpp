/*************************************************************************
	> File Name: 17-9-16.4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月16日 星期六 12时10分58秒
 ************************************************************************/

//船长的代码

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
 
class HashFunc {
public :
    virtual int operator()(const void *data) const {
        const char *str = static_cast<const char *>(data);
        int hash = 0;
        for (int i = 0; str[i]; i++) {
            hash = (hash << 5) ^ str[i] ^ (hash >> 3);
        }
        return (hash & 0x7fffffff);
    }
    virtual int operator()(int data) const {
        return data;
    }
    virtual int operator()(double data) const {
        return 2 * data;
    }
};

class HashTable {
public :
    HashTable(const HashFunc &func) : __func(&func) {}
    int get_hash(const void *data) {
        return (*(this->__func))(data);
    }
    int get_hash(int data) {
        return (*(this->__func))(data);
    }
    int get_hash(double data) {
        return (*(this->__func))(data);
    }
private :
    const HashFunc *__func;
};
 
class my_HashFunc : public HashFunc {
public :
    int operator()(const void *data) const override {
        const char *str = static_cast<const char *>(data);
        int hash = 0;
        for (int i = 0; str[i]; i++) {
            hash = (hash << 7) ^ str[i] ^ (hash >> 5);
        }
        return (hash & 0x7fffffff);
    }
};
 
class my_HashFunc2 : public HashFunc {
public :
    int operator()(int data) const override {
        return data << 5;
    }
};

class my_HashFunc3 : public HashFunc {
public :/*
    int operator()(const void *data) const override {
        const char *str = static_cast<const char *>(data);
        int hash = 0;
        for (int i = 0; str[i]; i++) {
            hash = (hash << 2) ^ str[i] ^ (hash >> 5);
        }
        return (hash & 0x7fffffff);
    }*/
    int operator()(const double data) const override {
        return (int)(data * 8) ^ (int)(data / 2);
    }
};
 
int main() {
    HashFunc hf;
    HashTable ht(hf);
    my_HashFunc hf1;
    HashTable ht1(hf1);
    my_HashFunc2 hf2;
    HashTable ht2(hf2);
    my_HashFunc3 hf3;
    HashTable ht3(hf3);
    cout << ht.get_hash("haizei") << endl;
    cout << ht1.get_hash("haizei") << endl;
    cout << ht2.get_hash(678) << endl;
    cout << ht3.get_hash(88.2f) << endl;
    return 0;
}
