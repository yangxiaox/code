/*************************************************************************
	> File Name: bbtree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月15日 星期三 21时29分30秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct RBTNode {
	int key;
	int black;
	struct RBTNode *lchild, *rchild;
	struct RBTNode *father;
} RBTNode;

RBTNode *NIL;

void init_NIL() {
	NIL = (RBTNode *)malloc(sizeof(RBTNode));
	NIL->father = NULL;
	NIL->lchild = NIL->rchild = NIL;
	NIL->key = 0;
	NIL->black = 1;
}

RBTNode *init(int key) {
	RBTNode *p = (RBTNode *)malloc(sizeof(RBTNode));
	p->father = NULL;
	p->lchild = p->rchild = NIL;
	p->key = key;
	p->black = 0;
	return p;
}

void clear(RBTNode *node) {
	if (node == NULL || node == NIL) return ;
	clear(node->lchild);
	clear(node->rchild);
	free(node);
	return ;
}

void clear_NIL() {
	free(NIL);
	NIL = NULL;
}

int has_red_child(RBTNode *node) {
	return node->lchild->black == 0 || node->rchild->black == 0; 
}

RBTNode *left_rotate(RBTNode *node) {
	RBTNode *temp = node->rchild;
	temp->father = node->father;
	node->father = temp;
	temp->lchild->father = node;
	node->rchild = temp->lchild;
	temp->lchild = node;
	return temp;
}

RBTNode *right_rotate(RBTNode *node) {
	RBTNode *temp = node->lchild;
	temp->father = node->father;
	node->father = temp;
	temp->rchild->father = node;
	node->lchild = temp->rchild;
	temp->rchild = node;
	return temp;
}

RBTNode *insert_maintain(RBTNode *node) {
	if (node->black == 0) return node;
	RBTNode *lchild = node->lchild;
	RBTNode *rchild = node->rchild;
	if (lchild->black && rchild->black) return node;
	if (!has_red_child(lchild) && !has_red_child(rchild)) return node;
	if (lchild->black == 0 && rchild->black == 0) {
		lchild->black = rchild->black = 1;
		node->black = 0;
		return node;
	}
	if (lchild->black == 0 && lchild->lchild->black == 0) {
		// LL
		node = right_rotate(node);
		node->lchild->black = 1;
	} else if (lchild->black == 0 && lchild->rchild->black == 0) {
		// LR
		node->lchild = left_rotate(node->lchild);
		node = right_rotate(node);
		node->lchild->black = 1;
	} else if (rchild->black == 0 && rchild->rchild->black == 0) {
		// RR
		node = left_rotate(node);
		node->rchild->black = 1;
	} else if (rchild->black == 0 && rchild->lchild->black == 0) {
		// RL
		node->rchild = right_rotate(node->rchild);
		node = left_rotate(node);
		node->rchild->black = 1;
	}
	return node;
}

RBTNode *insert(RBTNode *node, int key) {
	if (node == NULL || node == NIL) {
		RBTNode *temp = init(key);
		temp->black = (node == NULL);
		return temp;
	}
	if (node->key == key) return node;
	if (node->key < key) {
		node->rchild = insert(node->rchild, key);
		node->rchild->father = node;
		node = insert_maintain(node);
	} else {
		node->lchild = insert(node->lchild, key);
		node->lchild->father = node;
		node = insert_maintain(node);
	}
	if (node->father == NULL) {
		node->black = 1;
	}
	return node;
}

RBTNode *predecessor(RBTNode *node) {
	RBTNode *temp = node->lchild;
	while (temp->rchild != NIL) temp = temp->rchild;
	return temp;
}

RBTNode *erase_maintain(RBTNode *node) {
	if (node->lchild->black != 2 && node->rchild->black != 2) return node;
	RBTNode *lchild = node->lchild;
	RBTNode *rchild = node->rchild;
	if (lchild->black == 2 && rchild->black == 0) {
		node = left_rotate(node);
		node->black = 1;
		node->lchild->black = 0;
		node->lchild = erase_maintain(node->lchild);
	} else if (rchild->black == 2 && node->lchild == 0) {
		node = right_rotate(node);
		node->black = 1;
		node->rchild->black = 0;
		node->rchild = erase_maintain(node->rchild);
	} else if (lchild->black == 2 && rchild->black == 1) {
		if (!has_red_child(rchild)) {
			rchild->black = 0;
			lchild->black = 1;
			node->black++;
			return node;
		} else if (rchild->rchild->black != 0) {
			node->rchild = right_rotate(node->rchild);
			node->rchild->black = 1;
			node->rchild->rchild->black = 0;
		}
		node = left_rotate(node);
		node->black = node->lchild->black;
		node->lchild->black = node->rchild->black = 1;
		node->lchild->lchild->black = 1;
	} else if (rchild->black == 2 && lchild->black == 1) {
		if (!has_red_child(lchild)) {
			lchild->black = 0;
			rchild->black = 1;
			node->black++;
			return node;
		} else if (lchild->lchild->black != 0) {
			node->lchild = left_rotate(node->lchild);
			node->lchild->black = 1;
			node->lchild->lchild->black = 0;
		}
		node = right_rotate(node);
		node->black = node->rchild->black;
		node->lchild->black = node->rchild->black = 1;
		node->rchild->rchild->black = 1;
	}
	return node;
}

RBTNode *erase(RBTNode *node, int key) {
	if (node == NULL || node == NIL) {
		return node;
	}
	if (key > node->key) {
		node->rchild = erase(node->rchild, key);
		node = erase_maintain(node);
	} else if (key < node->key) {
		node->lchild = erase(node->lchild, key);
		node = erase_maintain(node);
	} else {
		if (node->lchild == NIL && node->rchild == NIL) {
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
			temp->key ^= node->key;
			node->key ^= temp->key;
			temp->key ^= node->key;
			node->lchild = erase(node->lchild, key);
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
	printf("%d (%d, %d, %d)\n", node->key, node->black, node->lchild->key, node->rchild->key);
	inorder(node->rchild);
	return ;
}

int main() {
	init_NIL();
	int opr, n;
	RBTNode *root = NULL;
	while (scanf("%d%d", &opr, &n) != EOF) {
		switch (opr) {
			case 1:
				root = insert(root, n);
				break;
			case 2:
				root = erase(root, n);
				break;
		}
		inorder(root);
		printf("-------------------\n");
	}
	clear_NIL();
	return 0;
}
