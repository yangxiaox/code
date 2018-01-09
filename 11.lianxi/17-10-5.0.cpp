/*************************************************************************
	> File Name: 17-10-5.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月05日 星期四 22时08分26秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <unistd.h>
#include <queue>
#include <list>
#include <pthread.h>

#include "23_yx.h"
using namespace std;
using yxx::HashTable;

queue<pair<string, int>, list<pair<string, int>>> q;
HashTable<string, int> ht;

void *f1(void *arg) {
    if (q.front().second == 1) {
        cout << q.front().first << (ht.search_y(q.front().first) ? "exist" : "not exist") << endl;
    } else {
        __sync_lock_test_and_set(&ht[q.front().first], 1);
        cout << q.front().first << "insert ok" << endl;
    }
    
    
    
    return NULL;
}

int main() {
    pthread_t thread[5];
    for (int i = 0; i < 5; ++i) {
          int  err = pthread_create(&thread[i], NULL, f1, NULL);
        //int w = pthread_create(&thread[i], NULL, f1, NULL);
    }
    pair<string, int> pp;
    pp.first = "hello";
    pp.second = 1;
    q.push(pp);
    /*for (int i = 0; i < 10; ++i) {
        cin >> pp.first >> pp.second;
        q.push(pp);
    }*/

    
    
    return 0;
}



