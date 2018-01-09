/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月07日 星期二 18时37分39秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct BSTNode {
    int key;
    BSTNode *lchild, *rchild;
    BSTNode *father;
};

BSTNode *init(int key, BSTNode *father) {
    BSTNode *p = (BSTNode *)malloc(sizeof(BSTNode));
    p->lchild = p->rchild = NULL;
    p->father = father;
    p->key = key;
    return p;
}

void clear(BSTNode *node) {
    if (node == NULL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

BSTNode *insert(BSTNode *node, int value) {
    if (node == NULL) {
        return init(value, NULL);
    }
    if (value == node->key) return node;
    if (value > node->key) {
        node->rchild = insert(node->rchild, value);
        node->rchild->father = node;
    } else {
        node->lchild = insert(node->lchild, value);
        node->lchild->father = node;
    }
    return node;
}

BSTNode *predecessor(BSTNode *node) {
    if (node->lchild == NULL) return NULL;
    BSTNode *temp = node->lchild;
    while (temp->rchild) {
        temp = temp->rchild;
    }
    return temp;
}

BSTNode *delete_node(BSTNode *node, int value) {
    if (node == NULL) {
        return NULL;
    }
    if (value > node->key) {
        node->rchild = delete_node(node->rchild, value);
    } else if (value < node->key) {
        node->lchild = delete_node(node->lchild, value);
    } else {
        if (node->lchild == NULL && node->rchild == NULL) {
            free(node);
            return NULL;
        } else if (node->lchild == NULL || node->rchild == NULL) {
            BSTNode *temp = node->lchild ? node->lchild : node->rchild;
            temp->father = node->father;
            free(node);
            return temp;
        } else {
            BSTNode *temp = predecessor(node);
            swap(node->key, temp->key);
            node->lchild = delete_node(node->lchild, value);
            return node;
        }
    }
    return node;
}

void inorder(BSTNode *root) {
    if (root == NULL) {
        return ;
    }
    inorder(root->lchild);
    printf("%d ", root->key);
    inorder(root->rchild);
    return ;
}

int main() {
    int opr, n;
    BSTNode *root = NULL;
    while (scanf("%d%d", &opr, &n) != EOF) {
        switch (opr) {
            case 1:
                root = insert(root, n);
                break;
            case 2:
                root = delete_node(root, n);
                break;
        }
        inorder(root);
        cout << endl;
    }
    return 0;
}

