/*************************************************************************
	> File Name: 17-11-8.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月08日 星期三 10时03分13秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct Node{
    char data;
    Node *lchild, *rchild;
};

Node *init(char val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->lchild = nullptr;
    node->rchild = nullptr;
    return node;
}

Node *__bulud(char *middle, char *behind, int length) {
    if (middle == nullptr || behind == nullptr || length == 0) return nullptr;
    char father = behind[length - 1];
    int num = 0;
    while (middle[num] != father) {
        ++num;
        if (num == length) {
            int a;
            throw a;
        }
    }
    Node *node = init(father);
    node->lchild = __bulud(middle, behind, num);
    node->rchild = __bulud(middle + num + 1, behind + num, length - num - 1);
    return node;
}

Node *bulud(char *middle, char *behind) {
    if (middle == nullptr || behind == nullptr) {
        cout << "Length is too short !" << endl;
        return nullptr;
    }
    int m = 0, n = 0;
    while (middle[m] != '\0') {
        ++m;
    }
    while (behind[n] != '\0') {
        ++n;
    }
    if (n != m) {
        cout << "Invalid input !" << endl;
        return nullptr;
    }
    try {
        Node *node = __bulud(middle, behind, m);
        return node;
    } 
    catch (int) {
        cout << "Data error !" << endl;
        return nullptr;
    }
}

void before_ergodic(Node *node) {
    if (node == nullptr) return ;
    cout << node->data << " ";
    before_ergodic(node->lchild);
    before_ergodic(node->rchild);
    return ;
}

void clear(Node *node) {
    if (node == nullptr) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

int main() {
    int n;
    cin >> n;
    char *middle = (char *)malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; ++i) {
        cin >> middle[i];
    }
    char *behind = (char *)malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; ++i) {
        cin >> behind[i];
    }
    char *a, *b;
    Node *node = bulud(middle, behind);
    before_ergodic(node);
    cout << endl;
    clear(node);
    return 0;
}
