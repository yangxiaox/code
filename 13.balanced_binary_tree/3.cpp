/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月09日 星期四 20时33分42秒
 ************************************************************************/

//AVLNode tree

#include<iostream>
using namespace std;

#define max(a, b) ({ \
    __typeof(a) temp_a = (a); \
    __typeof(b) temp_b = (b); \
    temp_a > temp_b ? temp_a : temp_b; \
})

struct AVLNode {
    int data;
    int height;
    AVLNode *lchild, *rchild;
};

AVLNode *init(int value) {
    AVLNode *p = (AVLNode *)malloc(sizeof(AVLNode));
    p->data = value;
    p->height = 1;
    p->lchild = p->rchild = nullptr;
    return p;
}

void clear(AVLNode *node) {
    if (node == nullptr) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

int tree_height(AVLNode *node) {             //树高
    if (node == nullptr) return 0;
    return node->height;
}

int calc_height(AVLNode *node) {             //更新树高
    if (node == nullptr) return 0;
    return max(tree_height(node->lchild), tree_height(node->rchild)) + 1;
}

AVLNode *right_rotate(AVLNode *node) {          //右旋
    AVLNode *temp = node->lchild;
    node->lchild = temp->rchild;
    temp->rchild = node;
    node->height = calc_height(node);
    temp->height = calc_height(temp);
    return temp;
}

AVLNode *left_rotate(AVLNode *node) {             //左旋
    AVLNode *temp = node->rchild;
    node->rchild = temp->lchild;
    temp->lchild = node;
    node->height = calc_height(node);
    temp->height = calc_height(temp);
    return temp;
}

AVLNode *maintain(AVLNode *node, int falg) {
    node->height = calc_height(node);
    if (falg == 1) {  //zuo shiheng
        if (tree_height(node->lchild) < tree_height(node->rchild)) {
            node->lchild = left_rotate(node->lchild);
        }
        node = right_rotate(node);
    } else {  //you shiheng
        if (tree_height(node->rchild) < tree_height(node->lchild)) {
            node->rchild = right_rotate(node->rchild);
        }
        node = left_rotate(node);
    }
    return node;
}

AVLNode *insert(AVLNode *node, int value) {
    if (node == nullptr) {
        return init(value);
    } else if (node->data == value) {
        return node;
    } else if (node->data > value) {
        node->lchild = insert(node->lchild, value);
    } else {
        node->rchild = insert(node->rchild, value);
    }
    if (abs(tree_height(node->lchild) - tree_height(node->rchild)) <= 1) {
        node->height = max(tree_height(node->lchild), tree_height(node->rchild)) + 1;
        return node;
    } else {
        node = maintain(node, value < node->data);
        return node;
    }
}

AVLNode *predecessor(AVLNode *node) {
    AVLNode *temp = node->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

AVLNode *delete_node(AVLNode *node, int value) {
    if (node == nullptr) return nullptr;
    if (node->data < value) {
        node->rchild = delete_node(node->rchild, value);
        node = maintain(node, 1);
    } else if (node->data > value) {
        node->lchild = delete_node(node->lchild, value);
        node = maintain(node, 0);
    } else {
        if (node->lchild == nullptr && node->rchild == nullptr) {
            free(node);
            return nullptr;
        } else if (node->lchild == nullptr || node->rchild == nullptr) {
            AVLNode *temp = node->lchild ? node->lchild : node->rchild;
            free(node);
            return temp;
        } else {
            AVLNode *temp = predecessor(node);
            temp->data ^= node->data;
            node->data ^= temp->data;
            temp->data ^= node->data;
            node->lchild = delete_node(node->lchild, value);
            node = maintain(node, 0);
        }
    }
    return node;
}

void inorder(AVLNode *node) {
    if (node == nullptr) return ;
    inorder(node->lchild);
    printf("%d(%d, %d)\n", node->data, tree_height(node->lchild), tree_height(node->rchild));
}

int main() {
    return 0;
}
