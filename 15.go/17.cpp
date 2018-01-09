/*************************************************************************
	> File Name: 17.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月23日 星期四 19时04分43秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int val = 0;

struct HashTable {
    string str;
    int value;
    int flag;
};

struct Hashdata{
    HashTable **data;
    int n;
};

Hashdata *init(int n) {
    Hashdata *hd = (Hashdata *)malloc(sizeof(Hashdata));
    hd->data = (HashTable **)malloc(sizeof(HashTable *) * n * 100);
    hd->n = n * 100;
    return hd;
}

int hashfunc(string str, int size) {
    int index = 0;
    for (int i = 0; i < str.length(); ++i) {
        index = ((index << 2) & (str[i] >> 1)) % size;
    }
    return index;
}

int find(Hashdata *hd, string str, int flag) {
    int index = hashfunc(str, hd->n);
    int ind = 1;
    for (int i = 1; i < hd->n; ++i) {
        if (hd->data[index] == NULL) {
            return 0;
        }
        if (hd->data[index]->str == str) {
            if (hd->data[index]->flag != flag) {
                hd->data[index]->flag = flag;
                val = hd->data[index]->value;
                return 1;
            } else {
                val = 0;
                return 1;
            }
        } else {
            index += ind;
            index %= hd->n;
            ind++;
        }
    }
}

void insert(Hashdata *hd, HashTable *ht) {
    int index = hashfunc(ht->str, hd->n);
    int ind = 1;
    for (int i = 1; i < hd->n; ++i) {
        if (hd->data[index] == NULL) {
            hd->data[index] = ht;
        } else {
            index += ind;
            index %= hd->n;
            ind++;
        }
    }
    return ;
}


int main() {
    int n;
    

    cin >> n;
    Hashdata *hd = init(n);
    for (int i = 0; i < n; ++i) {
        HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
        string str;
        int value;
        cin >> str >> value;
        ht->str = str;
        ht->value = value;
        ht->flag = -1;
        insert(hd, ht);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        long long sum = 0;
        int num;
        string name;
        cin >> num;
        int ff = 1;
        for (int j = 0; j < num; ++j) {
            cin >> name;
            ff = ff & find(hd, name, i);
            sum += val;
        }
        if (!ff) {
            cout << ff - 1 << endl;
        } else {
            cout << sum << endl;
        }
    }
    return 0;
}
