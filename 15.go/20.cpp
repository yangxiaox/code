/*************************************************************************
	> File Name: 20.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月23日 星期四 23时37分13秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

struct UnionSet {
    int *father, *size;
    int n;
};

UnionSet *init(int n) {
    UnionSet *p = (UnionSet *)malloc(sizeof(UnionSet));
    p->father = (int *)malloc(sizeof(int) * n + 1);
    p->size = (int *)malloc(sizeof(int) * n + 1);
    p->n = n + 1;
    for (int i = 0; i < n; ++i) {
        p->father[i] = i;
    }
    return p;
}

int find(UnionSet *u, int ind) {
    if (u->father[ind] == ind) {
        return ind;
    }
    u->father[ind] = find(u, u->father[ind]);
    return u->father[ind];
}

int merge(UnionSet *u, int p, int q) {
    int father_p = find(u, p);
    int father_q = find(u, q);
    if (father_p == father_q) return 0;
    if (u->size[father_p] < u->size[father_q]) {
        u->father[father_q] = father_p;
    } else { 
        u->father[father_p] = father_q;
    }
    return 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    UnionSet *u = init(n);
    for (int i = 0; i < n; ++i) {
        cin >> u->size[i];
    }
    for (int i = 0; i < m; ++i) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        merge(u, temp1 - 1, temp2 - 1);
    }
    long long x = 0;
    for (int i = 0; i < n; ++i) {
        if (i != find(u, i)) continue;
        x += u->size[i];
    }
    cout << x << endl;
    return 0;
}
