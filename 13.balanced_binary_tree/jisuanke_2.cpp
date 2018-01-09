/*************************************************************************
	> File Name: jisuanke_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月12日 星期日 14时28分15秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

struct TNode {
    int value;
    TNode *lchild, *rchild, *father;
};

struct Stack {
    TNode **data;
    int top, size;
};

Stack *init_stack(int size) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (TNode **)malloc(sizeof(TNode *) * size);
    s->size =size;
    s->top = -1;
    return s;
}

void push_stack(Stack *s, TNode *node) {
    s->data[++(s->top)] = node;
    return ;
}

void pop_stack(Stack *s) {
    (s->top)--;
    return ;
}

int empty_stack(Stack *s) {
    return s->top == -1;
}

TNode *top_stack(Stack *s) {
    if (empty_stack(s)) return nullptr;
    return s->data[s->top];
}

void clear_stack(Stack *s) {
    free(s->data);
    free(s);
    return ;
}

TNode *init(int value, TNode *father) {
    TNode *node = (TNode *)malloc(sizeof(TNode));
    node->value = value;
    node->father = father;
    node->lchild = nullptr;
    node->rchild = nullptr;
    return node;
}

void clear(TNode *node) {
    if (node == nullptr) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

void Print(TNode *node) {
    if (node == nullptr) {
        cout << '-';
        return ;
    }
    cout << node->value;
    if (node->lchild == nullptr && node->rchild == nullptr) {
        return ;
    }
    cout << "(";
    Print(node->lchild);
    cout << ",";
    Print(node->rchild);
    cout << ")";
    return ;
}

void Go_(TNode *root, int value) {
    TNode *max = nullptr;
    TNode *node = root;
    while (1) {
        if (node == nullptr) break;
        if (node->value == value) {
            max = node;
            break;
        } else if (node->value < value) {
            max = node;
            node = node->rchild;
        } else {
            node = node->lchild;
        }
    }
    TNode *l = max;
    TNode *r = root;
    if (l) {
        r = max->rchild;
        max->rchild = nullptr;
    }
    while (max && max != root) {
        if (max == max->father->lchild) {
            max->father->lchild = r;
            r = max->father;
        } else {
            max->father->rchild = l;
            l = max->father;
        }
        max = max->father;
    }
    Print(l);
    cout << endl;
    Print(r);
    cout << endl;
    return ;
}

TNode *build(char *str) {
    TNode *p = nullptr, *last_p = nullptr;
    Stack *s = init_stack(strlen(str));
    int k = 0;
    while (str[0]) {
        switch(str[0]) {
            case '(' :
                k = 0;
                push_stack(s, p);
                p = nullptr;
                break;
            case ')' :
                last_p = top_stack(s);
                pop_stack(s);
                break;
            case ',' :
                k = 1;
                p = nullptr;
                break;
            case ' ' :
            case '-' :
                break;
            default :
            if (p == nullptr){
                p = init(str[0] - '0', top_stack(s));
            } else {
                p->value = p->value * 10 + str[0] - '0';
            }
            if (!empty_stack(s) && k == 0) {
                top_stack(s)->lchild = p;
                k = -1;
            } else if (!empty_stack(s) && k == 1) {
                top_stack(s)->rchild = p;
                k = -1;
            }
            break;
        }
        ++str;
    }
    if (p && !last_p) last_p = p;
    clear_stack(s);
    return last_p;
}

int main() {
    char str[10000];
    int value;
    scanf("%[^\n]s", str);
    TNode *root = build(str);
    cin >> value;
    Go_(root, value);
    return 0;
}
