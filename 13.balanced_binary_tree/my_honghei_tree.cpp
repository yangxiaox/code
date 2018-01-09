/*************************************************************************
	> File Name: my_honghei_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月15日 星期三 17时54分53秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct BLTNode {
    int value;
    int black;
    BLTNode *lchild, *rchild;
    BLTNode *father;
};

BLTNode *NIL;

void init_NIL() {
    NIL = (BLTNode *)malloc(sizeof(BLTNode));
    NIL->value = 0;
    NIL->black = 1;
    NIL->lchild = NIL->rchild = NIL;
    NIL->father = NULL;
    return ;
}

void clear_NIL() {
    free(NIL);
    NIL = NULL;
    return ;
}

BLTNode *init(int value) {
    BLTNode *p = (BLTNode *)malloc(sizeof(BLTNode));
    p->value = value;
    p->lchild = p->rchild = NIL;
    p->black = 0;
    p->father = NULL;
    return p;
}

void clear(BLTNode *node) {
    if (node == NULL || node == NIL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

int bread_tree(BLTNode *node) {                            //有红返回1, 无红返回0
    return !node->lchild->black || !node->rchild->black;
}

BLTNode *left_rotate(BLTNode *node) {
    BLTNode *temp = node->rchild;
    temp->father = node->father;;
    temp->lchild->father = node;
    node->father = temp;
    node->rchild = temp->lchild;
    temp->lchild = node;
    return temp;
}

BLTNode *right_rotate(BLTNode *node) {
    BLTNode *temp = node->lchild;
    temp->father = node->father;
    temp->rchild->father = node;
    node->father = temp;
    node->lchild = temp->rchild;
    temp->rchild = node;
    return temp;
}

BLTNode *insert_maintain(BLTNode *node) {
    if (node == NULL || node == NIL) return node;
    if (node->black == 0) return node;
    if (!bread_tree(node)) return node;
    BLTNode *lchild = node->lchild;
    BLTNode *rchild = node->rchild;
    if (!bread_tree(lchild) && !bread_tree(rchild)) return node;
    if (lchild->black == 0 && rchild->black == 0) {
        lchild->black = rchild->black = 1;
        node->black--;
    } else if (lchild->black == 0 && bread_tree(lchild)) {
        if (lchild->rchild->black == 0) {
            node->lchild = left_rotate(node->lchild);
        }
        node = right_rotate(node);
        node->rchild->black = 0;
        node->black = 1;
    } else if (rchild->black == 0 && bread_tree(rchild)){
        if (rchild->lchild->black == 0) {
            node->rchild = right_rotate(node->rchild);
        }
        node = left_rotate(node);
        node->lchild->black = 0;
        node->black = 1;
    }
    return node;
}

BLTNode *insert(BLTNode *node, int value) {
    if (node == NIL || node == NULL) {
        BLTNode *temp = init(value);
        temp->black = (node == NULL);
        return temp;
    }
    if (node->value == value) return node;
    if (node->value > value) {
        node->lchild = insert(node->lchild, value);
        node->lchild->father = node;
        //insert_maintain(node->lchild);
    } else {
        node->rchild = insert(node->rchild, value);
        node->rchild->father = node;
        //insert_maintain(node->rchild);
    }
    node = insert_maintain(node);
    if (node->father == NULL) {
        node->black = 1;
    }
    return node;
}

BLTNode *pressonsed(BLTNode *node) {
    BLTNode *temp = node->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

BLTNode *earse_maintain(BLTNode *node) {
    if (node == NIL || node == NULL) return node;
    if (node->lchild->black != 2 && node->rchild->black != 2) return node;
    if (node->black == 1) {
        if (node->lchild->black == 2) {
            if (node->rchild->black == 1) {
                if (!bread_tree(node->rchild)) {
                    node->lchild->black = 1;
                    node->rchild->black = 0;
                    node->black+=1;
                    return node;
                }
                if (node->rchild->rchild->black != 0) {
                    node->rchild = right_rotate(node->rchild);
                    node->black = 1;
                    node->rchild->black = 0;
                }
                node = left_rotate(node);
                node->lchild->lchild->black = 1;
                node->rchild->black = 1;
            } else {
                node = left_rotate(node);
                node->black = 1;
                node->lchild->black = 0;
                node->lchild = earse_maintain(node->lchild);
            }
        } else {
            if (node->lchild->black == 1) {
                if (!bread_tree(node->lchild)) {
                    node->rchild->black = 1;
                    node->lchild->black = 0;
                    node->black += 1;
                    return node;
                }
                if (node->lchild->lchild->black != 0) {
                    node->lchild = left_rotate(node->lchild);
                    node->black = 1;
                    node->lchild->black = 0;
                }
                node = right_rotate(node);
                node->rchild->rchild->black = 1;
                node->lchild->black = 1;
            } else {
                node = right_rotate(node);
                node->black = 1;
                node->rchild->black = 0;
                node->rchild = earse_maintain(node->rchild);
            }
        }
    } else if (node->black == 0) {
        if (node->lchild->black == 2) {
            if (!bread_tree(node->rchild)) {
                node->lchild->black = 1;
                node->rchild->black = 0;
                node->black = 1;
                return node;
            } else if (node->rchild->rchild->black != 0) {
                node->rchild = right_rotate(node->rchild);
                node->rchild->black = 0;
                node->black = 1;
            }
            node = left_rotate(node);
            node->black = 0;
            node->lchild->black = node->rchild->black = 1;
            node->lchild->lchild->black = 1;
        } else {
            if (!bread_tree(node->lchild)) {
                node->rchild->black = 1;
                node->lchild->black = 0;
                node->black = 1;
            } else if (node->lchild->lchild->black != 0) {
                node->lchild = left_rotate(node->lchild);
                node->lchild->black = 0;
                node->black = 1;
            }
            node = right_rotate(node);
            node->black = 0;
            node->lchild->black = node->rchild->black = 1;
            node->rchild->rchild->black = 1;
        }
    }
    return node;
}

BLTNode *earse(BLTNode *node, int value) {
    if (node == NULL || node == NIL) return node;
    if (node->value > value) {
        node->lchild = earse(node->lchild, value);
        node = earse_maintain(node);
    } else if (node->value < value) {
        node->rchild = earse(node->rchild, value);
        node = earse_maintain(node);
    } else {
        if (node->lchild == NIL && node->rchild == NIL) {
            if (node->father == NULL) {
                free(node);
                return NULL;
            }
            NIL->black += node->black;
            NIL->father = node->father;
            free(node);
            return NIL;
        } else if (node->lchild == NIL || node->rchild == NIL) {
            BLTNode *temp = (node->lchild == NIL ? node->rchild : node->lchild);
            temp->black += node->black;
            temp->father = node->father;
            free(node);
            return temp;
        } else {
            BLTNode *temp = pressonsed(node);
            temp->value ^= node->value;
            node->value ^= temp->value;
            temp->value ^= node->value;
            node->lchild = earse(node->lchild, value);
            node = earse_maintain(node);
        }
    }
    if (node->father == NULL) {
        node->black = 1;
    }
    return node;
}

void inorder(BLTNode *node) {
    if (node == NULL || node == NIL) return ;
    inorder(node->lchild);
    printf("%d (%d, %d, %d)\n", node->value, node->black, node->lchild->value, node->rchild->value);
    inorder(node->rchild);
    return ;
}



int main() {
    init_NIL();
    BLTNode *root = NULL;
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        switch (a) {
            case 1 :
                root = insert(root, b);
                break;
            case 2 :
                root = earse(root, b);
                break;
            case 3 :
                inorder(root);
        }
    }
    clear(root);
    clear_NIL();
    return 0;
}
