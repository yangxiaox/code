/*************************************************************************
	> File Name: bingdu.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月25日 星期六 15时33分21秒
 ************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;

#define SIZE 4
#define MAX_N 200

typedef struct keda {
    int **data;
    int n;
} keda;

keda *init(int n) {
    keda *k = (keda *)malloc(sizeof(keda *));
    k->data = (int **)malloc(sizeof(int *) * n);
    k->n = n;
    for (int i = 0; i < n; ++i) {
        k->data[i] = (int *)calloc(n, sizeof(int));
    }
    return k;
}

typedef struct ACNode {
    int count;
    int id;
    struct ACNode *fail;
    struct ACNode **childs;
} ACNode;

int char_int(char c) {
    switch (c) {
        case 'A' : 
            return 0;
        case 'T' :
            return 1;
        case 'G' :
            return 2;
        case 'C' :
            return 3;
        default :
            printf("error\n");
            return -1;
    }
}

ACNode *new_node() {
    ACNode *node = (ACNode *)malloc(sizeof(ACNode));
    node->childs = (ACNode **)calloc(SIZE, sizeof(ACNode *));
    node->count = 0;
    node->id = 0;
    node->fail = NULL;
    return node;
}

void clear(ACNode *node) {
    if (node == NULL) return ;
    for (int i = 0; i < SIZE; ++i) {
        if (node->childs[i] != NULL) {
            clear(node->childs[i]);
        }
    }
    free(node->childs);
    free(node);
    return ;
}

void insert(ACNode *node, char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        if (node->childs[char_int(str[i])] == NULL) {
            node->childs[char_int(str[i])] = new_node();
        }
        node = node->childs[char_int(str[i])];
    }
    node->count++;
    return ;
}

int build(ACNode *root) {
    root->fail = root;
    ACNode *q[MAX_N];
    int l = 0, r = 0;
    q[r++] = root;
    int id = 1;
    while (l < r) {
        ACNode *now = q[l++];
        for (int i = 0; i < SIZE; ++i) {
            if (now->childs[i] == NULL) continue;
            ACNode *child = now->childs[i];
            if (now == root) {
                child->fail = root;
            } else {
                ACNode *iter = now;
                while (iter != root && iter->fail->childs[i] == NULL) {
                    iter = iter->fail;
                }
                if (iter != root) {
                    child->fail = iter->fail->childs[i];
                    child->count += iter->fail->childs[i]->count;
                } else {
                    child->fail = root;
                }
            }
            child->id = id;
            id++;
            q[r++] = child;
        }
    }
    return id;
}

int idid(int id, int sum) {
    if (id < sum * 3) return id;
    while (id >= sum * 3) {
        id -= sum;
    }
    return id;
}

void weight(keda *k, ACNode *root, ACNode *node, int ind, int sum) {
    for (int i = 0; i < 3; ++i) {
        if (node->childs[ind] == NULL) {
            ACNode *iter = node;
            while (iter != root && iter->fail->childs[ind] == NULL) {
                iter = iter->fail;
            }
            if (iter == root) {
                k->data[i * sum + node->id][i * sum]++;
            } else {
                int idd = idid(sum * (i + iter->fail->childs[ind]->count) + iter->fail->childs[ind]->id, sum);
                k->data[sum * i + node->id][idd]++;
            }
            continue;
        }
        int idd = idid(sum * (i + node->childs[ind]->count) + node->childs[ind]->id, sum);
        k->data[sum * i + node->id][idd]++;
    }
    return ;
}

void gogogo(ACNode *root, keda *k, int sum) {
    ACNode *q[MAX_N];
    int l = 0, r = 0;
    q[r++] = root;
    while (l < r) {
        ACNode *now = q[l++];
        for (int i = 0; i < SIZE; ++i) {
            weight(k, root, now, i, sum);
            if (now->childs[i] != NULL) {
                q[r++] = now->childs[i];
            }
        }
    }
    return ;
}

void clear_keda(keda *k) {
    for (int i = 0; i < k->n; ++i) {
        free(k->data[i]);
    }
    free(k->data);
    free(k);
    return ;
}

keda *power(keda *k1, keda *k2) {
    keda *the = init(k1->n);
    for (int i = 0; i < k1->n; ++i) {
        for (int j = 0; j < k1->n; ++j) {
            for (int o = 0; o < k1->n; ++o) {
                the->data[i][j] += k1->data[i][o] * k2->data[o][j];
                the->data[i][j] %= 10007;
            }
        }
    }
    clear_keda(k1);
    return the;
}

keda *copy(keda *k) {
    keda *base = init(k->n);
    for (int i = 0; i < k->n; ++i) {
        for (int j = 0; j < k->n; ++j) {
            base->data[i][j] = k->data[i][j];
        }
    }
    return base;
}

keda *func(keda *k, int n) {
    keda *base = copy(k);
    while (n) {
        if (n & 1) {
            k = power(k, base);
        }
        base = power(base, base);
        n >>= 1;
    }
    return k;
}

int main() {
    int n, l;
    char str[10];
    while (scanf("%d%d", &n, &l) != EOF) {
        ACNode *root = new_node();
        while (n--) {
            cin >> str;
            insert(root, str);
        }
        int sum = build(root);
        keda *k = init(sum * 3);
        gogogo(root, k, sum);
        for (int i = 0; i < k->n; ++i) {
            for (int j = 0; j < k->n; ++j) {
                cout << k->data[i][j] << " ";
            }
            cout << endl;
        }
        k = func(k, l - 1);
        int num = 0;
        for (int i = sum * 2; i < sum * 3; ++i) {
            num += k->data[0][i];
        }
        cout << (num % 10007) << endl;
    }
    return 0;
}
