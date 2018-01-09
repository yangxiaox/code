/*************************************************************************
	> File Name: 17-10-8.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月08日 星期日 11时43分59秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <queue>
#include <unistd.h>
#include <pthread.h>


using namespace std;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

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
template<> struct Hash<char> {
    int operator()(char a) {
        return a & 0x7fffffff;
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

template<typename KEY_T, typename HASHFUNC_T = Hash<KEY_T> >
class HashTable {
private:
    struct Node{
        KEY_T key;
        Node* next;
    };
    Node *__data;
    int __size;
    HASHFUNC_T __hash_func;
public:
    HashTable(int size = 100) : __size(size){
        this->__data = new Node[this->__size];
        for (int i = 0; i < this->__size; ++i) {
            //this->__data[i].key = "qqqqqqq";
            this->__data[i].next = nullptr;
        }
    }
    ~HashTable() {
        delete[] this->__data;
    }
    int find_h(KEY_T );
    int insert_h(KEY_T);
};

typedef pair<int ,string> pa;
queue<pa> q;
HashTable<string> ht;
int stop = 0;

void *func1(void *arg) {
    while (1) {
        if (stop) {
            break;
        }
        pthread_mutex_lock(&mutex1);
        while(q.empty()) ;
        pa p1 = q.front();
        q.pop();
        pthread_mutex_unlock(&mutex1);
        if (p1.first == 1) {
            int h = ht.find_h(p1.second);
            cout << "find " << p1.second << (h ? " OK" : " ERROR") << endl;
            pthread_mutex_unlock(&mutex2);
        } else if (p1.first == 2) {
            int h = ht.insert_h(p1.second);
            cout << "insert " << p1.second << (h ? " OK" : " ERROR") << endl;
            pthread_mutex_unlock(&mutex2);
        }
    }
    return NULL;
}






int main() {
    pa P;
    pthread_t thread[5];
    for (int i = 0; i < 5; ++i) {
        pthread_create(&thread[i], NULL, func1, NULL);
    }
    while (cin >> P.first) {
        cin >> P.second;
        q.push(P);
    }
    while (1) {
        if (q.empty()) {
            stop = 1;
            P.first = 3;
            int x = 5;
            while (x--) {
                q.push(P);
            }
            break;
        }
    }
    for (int i = 0; i < 5; ++i) {
        pthread_join(thread[i], NULL);
    }
    return 0;
}




template<typename KEY_T, typename HASHFUNC_T>
int HashTable<KEY_T, HASHFUNC_T>::find_h(KEY_T _key) {
          //  pthread_mutex_lock(&mutex2);
    int key_i = __hash_func(_key) % this->__size;
    Node *node = &(this->__data[key_i]);
    int flag = 0;
    while (1) {
       /* if (node == nullptr) {
            pthread_mutex_lock(&mutex2);
            if (node == nullptr) {
                break;
            }
            pthread_mutex_unlock(&mutex2);
        }*/
        if (node->key == _key) {
            flag = 1;
            break;
        }
        if (node->next == nullptr) {
            pthread_mutex_lock(&mutex2);
            if (node->next == nullptr) {
                break;
            }
            pthread_mutex_unlock(&mutex2);
        }
        node = node->next;
    }
    if (flag) {
        pthread_mutex_lock(&mutex2);
    }
    return flag;
}


template<typename KEY_T, typename HASHFUNC_T>
int HashTable<KEY_T, HASHFUNC_T>::insert_h(KEY_T _key) {
    int flag = find_h(_key);
    if (!flag) {
        int key_i = __hash_func(_key) % this->__size;
        Node *node1 = &(this->__data[key_i]);
        while (node1->next != nullptr) {
            node1 = node1->next;
        }
        Node *node2 = new Node[1];
        node2->key = _key;
        node2->next = nullptr;
        node1->next = node2;
    }
    return !flag;
}
