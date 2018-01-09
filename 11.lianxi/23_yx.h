/*************************************************************************
	> File Name: 17-9-19.0.h
	> Author: 
	> Mail: 
	> Created Time: 2017年09月19日 星期二 10时50分50秒
 ************************************************************************/

#ifndef _23_YX_H
#define _23_YX_H
 
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;
 
namespace yxx {

static int sync_lock = 0;

template<typename T> struct Hash;
template<> struct Hash<int> {
    int operator()(int a) {
        return a & 0x7fffffff;
    }
};
template<> struct Hash<double> {
    int operator()(double a) {
        return static_cast<int>(a) & 0x7fffffff;
    }
};
template<> struct Hash<string> {
    int operator()(const string &s) {
        int hash = 0;
        for (int i = 0; i < s.length(); i++) {
            hash = (hash << 5) ^ s[i] ^ (hash >> 3);
        }
        return (hash & 0x7fffffff);
    }
};
 
template<typename KEY_T, typename VALUE_T, typename HashFunc_T = Hash<KEY_T> >
class HashTable {
   
private :
    struct Node{
        KEY_T key;
        VALUE_T value;
        Node* next;
    };
    int __size;
    Node *__data;
    HashFunc_T __hash_func;

public :
    HashTable(int size = 100) : __size(size) {
        this->__data = new Node[this->__size];
        for (int i = 0; i < this->__size; ++i) {
            this->__data[i].next = nullptr;
        }
    }

    ~HashTable() {
        delete[] this->__data;
    }

    VALUE_T &operator[](const KEY_T &key) {
        int index = 1;
        Node *temp = this->find(key, &index);
        if (index) {
            temp->next->key = key;
            sync_lock = 0;
        }
        return temp->value;
    }
    
    Node *find(const KEY_T &key, int *_index = nullptr) {
        int hash_code = this->__hash_func(key);
        int index = hash_code % this->__size;
        Node *temp = &(this->__data[index]);
        while (1) {
            if (temp->next == nullptr) {
                while (!__sync_lock_test_and_set(&sync_lock, 1)) ;
                if (temp->next == nullptr) {
                    break;
                }
                sync_lock = 0;
            }
            if (temp->next->key == key) {
                *_index = 0;
                return temp->next;
            }
            temp = temp->next;
        }
        Node *temp2 = (Node *)malloc(sizeof(Node));
        temp2->value = 0;
        temp2->next = nullptr;
        temp->next = temp2;
        return temp;
    }
    bool search_y(const KEY_T &key) {
        int index = 1;
        Node* temp = this->find(key, &index);
        if (index) {
            free(temp->next);
            temp->next = nullptr;
            sync_lock = 0;
        }
        return !index;
    }
};
}
#endif
