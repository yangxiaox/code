/*************************************************************************
	> File Name: red_black_tree_test_2.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月16日 星期四 15时07分50秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct RBTNode {
    int value;
    int black;
    struct RBTNode *lchild, *rchild;
    struct RBTNode *father;
} RBTNode;

RBTNode *NIL;

void init_NIL() {
    NIL = (RBTNode *)malloc(sizeof(RBTNode));
    NIL->lchild = NIL->rchild = NIL;
    NIL->father = NULL;
    NIL->value = 0;
    NIL->black = 1;
    return ;
}

void clear_NIL() {
    free(NIL);
    NIL = NULL;
    return ;
}

RBTNode *init(int value) {
    RBTNode *node = (RBTNode *)malloc(sizeof(RBTNode));
    node->father = NULL;
    node->lchild = node->rchild = NIL;
    node->value = value;
    node->black = 0;
    return node;
}

void clear(RBTNode *node) {
    if (node == NULL || node == NIL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

RBTNode *left_rotate(RBTNode *node) {
    RBTNode *temp = node->rchild;
    temp->father = node->father;
    temp->lchild->father = node;
    node->father = temp;
    node->rchild = temp->lchild;
    temp->lchild = node;
    return temp;
}

RBTNode *right_rotate(RBTNode *node) {
    RBTNode *temp = node->lchild;
    temp->father = node->father;
    temp->rchild->father = node;
    node->father = temp;
    node->lchild = temp->rchild;
    temp->rchild = node;
    return temp;
}

int has_red_child(RBTNode *node) {
    return !node->lchild->black || !node->rchild->black;
}

RBTNode *insert_maintain(RBTNode *node) {
    if (node->black == 0) return node;
    if (!has_red_child(node)) return node;
    RBTNode *lchild = node->lchild, *rchild = node->rchild;
    if (!has_red_child(lchild) && !has_red_child(rchild)) return node;
    if (lchild->black == 0 && rchild->black == 0) {
        lchild->black = rchild->black = 1;
        node->black = 0;
        return node;
    } else if (lchild->black == 0 && has_red_child(lchild)) {
        if (lchild->lchild->black != 0) {
            node->lchild = left_rotate(node->lchild);
        }
        node = right_rotate(node);
        node->lchild->black = 1;
    } else if (rchild->black == 0 && has_red_child(rchild)) {
        if (rchild->rchild->black != 0) {
            node->rchild = right_rotate(node->rchild);
        }
        node = left_rotate(node);
        node->rchild->black = 1;
    }
    return node;
}

RBTNode *insert(RBTNode *node, int value) {
    if (node == NULL || node == NIL) {
        RBTNode *temp = init(value);
        temp->black = (node == NULL);
        return temp;
    }
    if (node->value == value) return node;
    if (node->value > value) {
        node->lchild = insert(node->lchild, value);
        node->lchild->father = node;
    } else {
        node->rchild = insert(node->rchild, value);
        node->rchild->father = node;
    }
    node = insert_maintain(node);
    if (node->father == NULL) {
        node->black = 1;
    }
    return node;
}

RBTNode *predecessor(RBTNode *node) {
    RBTNode *temp = node->lchild;
    while(temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

RBTNode *erase_maintain(RBTNode *node) {
    if (node->lchild->black != 2 && node->rchild->black != 2) return node;
    RBTNode *lchild = node->lchild, *rchild = node->rchild;
    if (lchild->black == 2 && rchild->black == 0) {
        node = left_rotate(node);
        node->black = 1;
        node->lchild->black = 0;
        node->lchild = erase_maintain(node->lchild);
    } else if (rchild->black == 2 && lchild->black == 0) {
        node = right_rotate(node);
        node->black = 1;
        node->rchild->black = 0;
        node->rchild = erase_maintain(node->rchild);
    } else if (lchild->black == 2 && rchild->black == 1) {
        if (!has_red_child(rchild)) {
            node->lchild->black = 1;
            node->rchild->black = 0;
            node->black += 1;
            return node;
        } else if (rchild->rchild->black != 0) {
            node->rchild = right_rotate(node->rchild);
            node->rchild->rchild->black = 0;
            node->rchild->black = 1;
        }
        node = left_rotate(node);
        node->black = node->lchild->black;
        node->lchild->black = node->rchild->black = 1;
        node->lchild->lchild->black = 1;
    } else if (rchild->black == 2 && lchild->black == 1) {
        if (!has_red_child(lchild)) {
            node->rchild->black = 1;
            node->lchild->black = 0;
            node->black += 1;
            return node;
        } else if (lchild->lchild->black != 0) {
            node->lchild = left_rotate(node->lchild);
            node->lchild->lchild->black = 0;
            node->lchild->black = 1;
        }
        node = right_rotate(node);
        node->black = node->rchild->black;
        node->lchild->black = node->rchild->black = 1;
        node->rchild->rchild->black = 1;
    }
    return node;
}

RBTNode *erase(RBTNode *node, int value) {
    if (node == NULL || node == NIL) return node;
    if (node->value > value) {
        node->lchild = erase(node->lchild, value);
        node = erase_maintain(node);
    } else if (node->value < value) {
        node->rchild = erase(node->rchild, value);
        node = erase_maintain(node);
    } else {
        if (node->lchild == NIL && node->rchild == NIL) {
            if (node->father == NULL) {
                free(node);
                return NULL;
            }
            NIL->black += node->black;
            free(node);
            return NIL;
        } else if (node->lchild == NIL || node->rchild == NIL) {
            RBTNode *temp = (node->lchild == NIL ? node->rchild : node->lchild);
            temp->black += node->black;
            temp->father = node->father;
            free(node);
            return temp;
        } else {
            RBTNode *temp = predecessor(node);
            temp->value ^= node->value;
            node->value ^= temp->value;
            temp->value ^= node->value;
            node->lchild = erase(node->lchild, value);
            node = erase_maintain(node);
        }
    }
    if (node->father == NULL) {
        node->black = 1;
    }
    return node;
}

void inorder(RBTNode *node) {
    if (node == NULL || node == NIL) return ;
    inorder(node->lchild);
    printf("%d (%d, %d, %d)\n", node->value, node->black, node->lchild->value, node->rchild->value);
    inorder(node->rchild);
    return ;
}

int main() {
    init_NIL();
    RBTNode *root = NULL;
    int opr, value;
    while(scanf("%d", &opr) != EOF) {
        switch (opr) {
            case 1 :
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2 :
                scanf("%d", &value);
                root = erase(root, value);
                break;
            case 3 :
                inorder(root);
                printf("-------------------------------------\n");
                break;
        }
    }
    clear(root);
    clear_NIL();
    return 0;
}
