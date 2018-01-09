/*************************************************************************
	> File Name: 5.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月14日 星期二 11时42分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct SBTNode {
    int data, size;
    struct SBTNode *lchild, *rchild, *father;
} SBTNode;

SBTNode *NIL;

SBTNode *init(int data, int size, SBTNode *father) {
    SBTNode *p = (SBTNode *)malloc(sizeof(SBTNode));
    p->data = data;
    p->size = size;
    p->father = father;
    p->lchild = NIL;
    p->rchild = NIL;
    return p;
}

void init_NIL() {
    NIL = (SBTNode *)malloc(sizeof(SBTNode));
    NIL->data = 0;
    NIL->size = 0;
    NIL->lchild = NIL;
    NIL->rchild = NIL;
    NIL->father = NULL;
}

SBTNode *search(SBTNode *node, int value) {
    if (node == NULL) {
        return NIL;
    } else if (node == NIL || node->data == value) {
        return node;
    } else if (node->data < value) {
        return search(node->rchild, value);
    } else {
        return search(node->lchild, value);
    }
}

SBTNode *left_rotate(SBTNode *node) {
    SBTNode *temp = node->rchild;
    temp->lchild->father = node;
    temp->father = node->father;
    node->father = temp;
    node->rchild = temp->lchild;
    temp->lchild = node;
    temp->size = node->size;
    node->size = node->lchild->size + node->rchild->size + 1;
    return temp;
}

SBTNode *right_rotate(SBTNode *node) {
    SBTNode *temp = node->lchild;
    temp->rchild->father = node;
    temp->father = node->father;
    node->father = temp;
    node->lchild = temp->rchild;
    temp->rchild = node;
    temp->size = node->size;
    node->size = node->lchild->size + node->rchild->size + 1;
    return temp;
}

SBTNode *maintain(SBTNode *node, int flag) {
    if (flag == 0) {
        if (node->lchild->lchild->size > node->rchild->size) {
            node = right_rotate(node);
        } else if (node->lchild->rchild->size > node->rchild->size) {
            node->lchild = left_rotate(node->lchild);
            node = right_rotate(node);
        } else {
            return node;
        }
    } else {
        if (node->rchild->rchild->size > node->lchild->size) {
            node = left_rotate(node);
        } else if (node->rchild->lchild->size > node->lchild->size) {
            node->rchild = right_rotate(node->rchild);
            node = left_rotate(node);
        } else {
            return node;
        }
    }
    node->lchild = maintain(node->lchild, 0);
    node->rchild = maintain(node->rchild, 1);
    node = maintain(node, 0);
    node = maintain(node, 1);
    return node;
}

SBTNode *__insert(SBTNode *node, int value) {
    node->size++;
    if (value > node->data) {
        if (node->rchild == NIL) {
            node->rchild = init(value, 1, node);
        } else {
            node->rchild = __insert(node->rchild, value);
        }
        node = maintain(node, 1);
    } else {
        if (node->lchild == NIL) {
            node->lchild = init(value, 1, node);
        } else {
            node->lchild = __insert(node->lchild, value);
        }
        node = maintain(node, 0);
    }
    return node;
}

SBTNode *insert_node(SBTNode *node, int value) {
    if (node == NULL) {
        return init(value, 1, NULL);
    }
    if (search(node, value) != NIL) {
        return node;
    }
    return __insert(node, value);
}

SBTNode *predecessor(SBTNode *node) {
    if (node == NULL || node->lchild == NIL) return NIL;
    SBTNode *temp = node->lchild;
    while (temp->rchild != NIL) {
        temp = temp->rchild;
    }
    return temp;
}

SBTNode *successor(SBTNode *node) {
    if (node == NULL || node->rchild == NIL) return NIL;
    SBTNode *temp = node->rchild;
    while (temp->lchild != NIL) {
        temp = temp->lchild;
    }
    return temp;
}

void remove_node(SBTNode *node) {
    SBTNode *temp = NIL;
    if (node->lchild != NIL) {
        temp = node->lchild;
        temp->father = node->father;
    } else if (node->rchild != NIL) {
        temp = node->rchild;
        temp->father = node->father;
    }
    if (node->father->lchild == node) {
        node->father->lchild = temp;
    } else if (node->father->rchild == node) {
        node->father->rchild = temp;
    }
    temp = node;
    while (temp != NULL) {
        temp->size--;
        temp = temp->father;
    }
    free(node);
}

SBTNode *delete_tree(SBTNode *node, int value) {
    SBTNode *current_node = search(node, value);
    SBTNode *delete_node = current_node;
    if (current_node == NIL) {
        return node;
    }
    if (node->size == 1 && node->data == value) {
        free(node);
        return NULL;
    }
    if (current_node->lchild != NIL) {
        delete_node = predecessor(current_node);
    } else if (current_node->rchild != NIL) {
        delete_node = successor(current_node);
    }
    current_node->data = delete_node->data;
    remove_node(delete_node);
    return node;
}

int clear(SBTNode *node) {
    node->lchild != NIL && clear(node->lchild);
    node->rchild != NIL && clear(node->rchild);
    free(node);
    return 1;
}

int query_kth(SBTNode *node, int k) {
    if (node == NULL || node == NIL) {
        return 0;
    } else if (k - 1 == node->rchild->size) {
        return node->data;
    } else if (node->rchild->size >= k) {
        return query_kth(node->rchild, k);
    } else {
        return query_kth(node->lchild, k - node->rchild->size - 1);
    }
}

int main() {
    init_NIL();
    SBTNode *root = NULL;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        root = insert_node(root, num);
    }
    for (int i = 0; i < m; i++) {
        char str[15];
        int num;
        scanf("%s%d", str, &num);
        switch (str[0]) {
            case 'q' :
                printf("%d\n", query_kth(root, num));
                break;
            case 'i' :
                root = insert_node(root, num);
                break;
            case 'd' :
                root = delete_tree(root, num);
                break;
        }
    }
    return 0;
}
