/*************************************************************************
	> File Name: AC.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月18日 星期六 19时51分15秒
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;

#define SIZE 256
#define MAX_N 10000

typedef struct ACNode {
    int count;
    struct ACNode *fail;
    struct ACNode **childs;
} ACNode;

ACNode *new_node() {
    ACNode *node = (ACNode *)malloc(sizeof(ACNode));
    node->childs = (ACNode **)calloc(SIZE, sizeof(ACNode *));
    node->count = 0;
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
        if (node->childs[str[i]] == NULL) {
            node->childs[str[i]] = new_node();
        }
        node = node->childs[str[i]];
    }
    node->count++;
    return ;
}

void build(ACNode *root) {
    root->fail = root;
    ACNode *q[MAX_N];
    int l = 0, r = 0;
    q[r++] = root;
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
                } else {
                    child->fail = root;
                }
            }
            q[r++] = child;
        }
    }
}

int match(ACNode *node, const char *buffer) {
    ACNode * temp = node;
    int count = 0;
    for (int i = 0; buffer[i]; ++i) {
        while (temp != node && temp->childs[buffer[i]] == NULL) {
            temp = temp->fail;
        }
        temp = temp->childs[buffer[i]];
        if (temp == NULL) {
            temp = node;
        }
        ACNode *p = temp;
        while (p != node) {
            count += p->count;
            p = p->fail;
        }
    }
    return count;
}

int main() {
    char child[100];
    char buffer[1000];
    int n;
    ACNode *root = new_node();
    while (1) {
        scanf("%d", &n);
        switch (n) {
            case 1 :
                scanf("%s", child);
                insert(root, child);
                build(root);
                break;
            case 2 :
                scanf("%s", buffer);
                printf("%d\n", match(root, buffer));
        }
    }
    clear(root);
    return 0;
}
