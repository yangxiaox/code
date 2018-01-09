/*************************************************************************
	> File Name: 4.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月11日 星期六 19时11分22秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ({ \
	__typeof(a) temp_a = (a); \
	__typeof(b) temp_b = (b); \
	temp_a > temp_b ? temp_a : temp_b; \
})

typedef struct AVLNode {
	int key;
	int height;
	struct AVLNode *lchild, *rchild;
} AVLNode;

AVLNode *init(int key) {
	AVLNode *p = (AVLNode *)malloc(sizeof(AVLNode) * 1);
	p->key = key;
	p->height = 1;
	p->rchild = p->lchild = NULL;
	return p;
}

void clear(AVLNode *node) {
	if (node == NULL) return ;
	clear(node->lchild);
	clear(node->rchild);
	free(node);
	return ;
}

int tree_height(AVLNode *node) {               //树高
	if (node == NULL) return 0;
	return node->height;
}

int calc_height(AVLNode *node) {             //更新树高
	if (node == NULL) return 0;
	return max(tree_height(node->lchild), tree_height(node->rchild)) + 1;
}

AVLNode *right_rotate(AVLNode *node) {                //右旋
	AVLNode *temp = node->lchild;
	node->lchild = temp->rchild;
	temp->rchild = node;
	node->height = calc_height(node);
	temp->height = calc_height(temp);
	return temp;
}

AVLNode *left_rotate(AVLNode *node) {                  //左旋
	AVLNode *temp = node->rchild;
	node->rchild = temp->lchild;
	temp->lchild = node;
	node->height = calc_height(node);
	temp->height = calc_height(temp);
	return temp;
}

int is_balaced(AVLNode *node) {                          //是否失衡
	return abs(tree_height(node->lchild) - tree_height(node->rchild)) <= 1;
}

AVLNode *maintain(AVLNode *node, int flag) {                 //flag方向是否需要调整  并作出相应调整
	node->height = calc_height(node);
	if (is_balaced(node)) return node;
	if (flag == 1) {
		if (tree_height(node->lchild) < tree_height(node->rchild)) {
			node->lchild = left_rotate(node->lchild);
		}
		node = right_rotate(node);
	} else {
		if (tree_height(node->rchild) < tree_height(node->lchild)) {
			node->rchild = right_rotate(node->rchild);
		}
		node = left_rotate(node);
	}
	return node;
}


AVLNode *insert(AVLNode *node, int key) {                //插入
	if (node == NULL) {
		return init(key);
	} else if (node->key == key) {
		return node;
	} else if (node->key > key) {
		node->lchild = insert(node->lchild, key);
	} else {
		node->rchild = insert(node->rchild, key);
	}                                                                                                      
	node = maintain(node, key < node->key);
	return node;
}

AVLNode *predecessor(AVLNode *node) {                               //前趋
	AVLNode *temp = node->lchild;
	while (temp->rchild) temp = temp->rchild;
	return temp;
}

AVLNode *delete_node(AVLNode *node, int key) {               //删除
	if (node == NULL) return NULL;
	if (node->key < key) {
		node->rchild = delete_node(node->rchild, key);
		node = maintain(node, 1);
	} else if (node->key > key) {
		node->lchild = delete_node(node->lchild, key);
		node = maintain(node, 0);
	} else {
		if (node->lchild == NULL && node->rchild == NULL) {
			free(node);
			return NULL;
		} else if (node->lchild == NULL || node->rchild == NULL) {
			AVLNode *temp = (node->lchild ? node->lchild : node->rchild);
			free(node);
			return temp;
		} else {
			AVLNode *temp = predecessor(node);
			temp->key ^= node->key;
			node->key ^= temp->key;
			temp->key ^= node->key;
			node->lchild = delete_node(node->lchild, key);
			node = maintain(node, 0);
		}
	}
	return node;
}

void inorder(AVLNode *node) {                      //输出
	if (node == NULL) return ;
	inorder(node->lchild);
	printf("%d(%d, %d)\n", node->key, tree_height(node->lchild), tree_height(node->rchild));
	inorder(node->rchild);
	return ;
}

int main() {
	int opr, n;
	AVLNode *root;
	while (scanf("%d%d", &opr, &n) != EOF) {
		switch (opr) {
			case 1:
				root = insert(root, n);
				break;
			case 2:
				root = delete_node(root, n);
				break;
		}
		printf("Inorder AVL Tree : \n");
		inorder(root);
		printf("-------------\n");
	}
	return 0;
}
