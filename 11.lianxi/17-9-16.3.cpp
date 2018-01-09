/*************************************************************************
	> File Name: 17-9-16.3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月16日 星期六 11时43分20秒
 ************************************************************************/


#include <iostream>
using namespace std;

class HashFunc {
public :
    virtual int operator()(const char *str) const{
        int hash = 0;
        for (int i = 0; str[i]; ++i) {
            hash = (hash << 5) ^ str[i] ^ (hash >> 3);
        }
        return (hash & 0x7fffffff);
    }
};

class HashTablee {
public :
    HashTablee(const HashFunc &func) : __func(&func) {}
    int get_hash(const char *str) {
        return (*(this->__func))(str);
    }
private :
    const HashFunc *__func;
};

class my_HashFunc : public HashFunc{
public :
    int operator()(const char *str) const override {
        int hash = 0;
        for (int i = 0; i < str[i]; ++i) {
            hash = (hash << 7) ^ str[i] ^ (hash >> 5);
        }
        return (hash & 0x7fffffff);
    } 
};

int main() {
    HashFunc hf;
    HashTablee ht(hf);
    my_HashFunc hf2;
    HashTablee ht2(hf2);
    cout << ht.get_hash("haizei") << endl;
    cout << ht2.get_hash("haizei") << endl;
    return 0;
}
