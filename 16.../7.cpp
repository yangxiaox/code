/*************************************************************************
	> File Name: 7.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月24日 星期五 18时30分16秒
 ************************************************************************/

#include <iostream>
#include <unordered_map>
#include <cstdio>
using namespace std;

class my_hash {
public:
    my_hash() : n(1e7 + 5) {
        this->mh = (pair<int, int> *)calloc(n, sizeof(pair<int, int>));
        this->mh2 = (pair<int, long long> *)calloc(n, sizeof(pair<int, long long>));
    }
    int hash_func(long long key) {
        return key % (int)(1e7 + 5);
    }
    pair<int, int> &operator[](long long key) {
        int ind = hash_func(key);
        while (this->mh2[ind].second != key && this->mh[ind].second != 0) {
            ind++;
            ind %= (int)(1e7 + 5);
        }
        if (this->mh[ind].second == 0) {
            this->mh2[ind].second = key;
        }
        return this->mh[ind];
    }
    
    pair<int, int> *mh;
    pair<int, long long> *mh2;
    int n;


};


my_hash mp;

int main() {
    int n;
    long long m;
    cin >> n >> m;
    for (int i = 0; i < (n / 100); ++i) {
        long long seed;
        scanf("%lld", &seed);
        for (int j = 0; j < 100; ++j) {
            mp[seed].second++;
            seed = (seed * 109 + 107) % m;
        }
    }
    long long sum = 0;
    for (int x = 0; x < (int)(1e7 + 5); ++x) {
        if (mp.mh2[x].second == 0) continue;
        if (mp[x].first + 1 >= mp[x].second) {
            sum += mp[x].first + 1;
        } else {
            sum += ((mp[x].second - 1) / (mp[x].first + 1) + 1) * (mp[x].first + 1);
        }
    }
    cout << sum << endl;
    return 0;
}
