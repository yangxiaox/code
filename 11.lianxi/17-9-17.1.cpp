/*************************************************************************
	> File Name: 17-9-17.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月17日 星期日 09时27分23秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

#define Print(a) (cout << a << endl)

template<typename KEY_T, typename VALUE_T, typename HashFunc_T>
class HashTable {
public :
    HashTable(int size = 100) : __size(size) {
        this->__data = new pair<KEY_T, VALUE_T>[this->__size];
        this->__map = new bool[this->__size]{0};
    }
    ~HashTable() {
        delete[] this->__data;
    }
    VALUE_T &operator[](const KEY_T &key) {
        int index;
        VALUE_T *temp = this->find(key, &index);
        if (temp == this->end() && index == -1) return this->__end;
        if (this->__map[index] == 0) {
            this->__data[index].first = key;
            this->__map[index] = true;
        }
        return this->__data[index].second;
    } 
    VALUE_T *end() {return &(this->__end);}
    VALUE_T *find(const KEY_T &key, int *_index = nullptr) {
        int hash_code = this->__hash_func(key);
        int index = hash_code % this->__size;
        int times = 1;
        while (this->__map[index] && this->__data[index].first != key) {
            index += (times * times);
            index %= this->__size;
            times++;
            if (times == this->__size) {
                if (_index != nullptr) {
                    *_index = -1;
                }
                return this->end();
            }
        }
        if (_index != nullptr) {
            *_index = index;
        }
        if (this->__map[index] == 0) return this->end();
        return &(this->__data[index].second);
    }
private:
    int __size;
    pair<KEY_T, VALUE_T> *__data;
    bool *__map;
    HashFunc_T __hash_func;
    VALUE_T __end;
};

class StringHash {
public :
    int operator()(const string &s) {
        int hash = 0;
        for (int i = 0; i < s.length(); ++i) {
            hash = (hash << 5) ^ s[i] ^ (hash >> 3);
        }
        return (hash & 0x7fffffff);
    }
};

int main() {
    HashTable<string, int, StringHash> ht;
    ht["hello"] = 1;
    ht["hello"]++;
    cout << ht["world"] << " " << ht["hello"] << endl;
    
    return 0;
}
