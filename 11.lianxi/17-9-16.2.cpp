/*************************************************************************
	> File Name: 17-9-16.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月16日 星期六 11时29分05秒
 ************************************************************************/

#include <iostream>
using namespace std;

class HashFunc {
public :
    int operator()(const char *str) {
        int hash = 0;
        for (int i = 0; str[i]; ++i) {
            hash = (hash << 5) ^ str[i] ^ (hash >> 3);
        }
        return (hash & 0x7fffffff);
    }
};

class HashTablee {
public :
    HashTablee(const HashFunc &func) : __func(func) {}
    int get_hash(const char *str) {
        return this->__func(str);
    }
private :
    HashFunc __func;
};

int main() {
    HashFunc hf;
    HashTablee ht(hf);
    cout << ht.get_hash("haizei") << endl;
    return 0;
}
