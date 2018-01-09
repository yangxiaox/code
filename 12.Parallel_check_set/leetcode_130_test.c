/*************************************************************************
	> File Name: leetcode_130_test.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月07日 星期二 11时45分21秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Union {
    int *father;
    int *size;
} Union;

Union *init(int n) {
    Union *u = (Union *)malloc(sizeof(Union));
    u->father = (int *)malloc(sizeof(int) * n);
    u->size = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n ; ++i) {
        u->father[i] = i;
        u->size[i] = 1;
    }
    return u;
}

void clear(Union *u) {
    free(u->father);
    free(u->size);
    free(u);
    return ;
}

int find(Union *u, int ind) {
    if (u->father[ind] == ind) {
        return ind;
    }
    u->father[ind] = find(u, u->father[ind]);
    return u->father[ind];
}

int merge(Union *u, int p, int q) {
    int father_p = find(u, p);
    int father_q = find(u, q);
    if (father_p == father_q) {
        return 0;
    }
    if (u->size[father_p] > u->size[father_q]) {
        father_p ^= father_q;
        father_q ^= father_p;
        father_p ^= father_q;
    }
    u->father[father_p] = father_q;
    u->size[father_q] += u->father[father_p];
    return 1;
}

void solve(char** board, int boardRowSize, int boardColSize) {
    int n = boardRowSize *boardColSize + 1;
    Union *u = init(n);
    for (int i = 0; i < boardRowSize; ++i) {
        for (int j = 0; j < boardColSize; ++j) {
            if (board[i][j] == 'X') continue;
            int ind = i * boardColSize + j + 1;
            if (i == 0 || i == boardRowSize - 1) {
                merge(u, ind, 0);
            } else if (j == 0 || j == boardColSize - 1) {
                merge(u, ind, 0);
            }
            if (i > 0 && board[i - 1][j] == 'O') {
                merge(u, ind, ind - boardColSize);
            }
            if (j > 0 && board[i][j - 1] == 'O') {
                merge(u, ind, ind - 1);
            }
        }
    }
    for (int i = 0; i < boardRowSize; ++i) {
        for (int j = 0; j < boardColSize; ++j) {
            if (board[i][j] == 'X') continue;
            int ind = i * boardColSize + j + 1;
            if (find(u, ind) != find(u, 0)) {
                board[i][j] = 'X';
            }
        }
    }
    return ;
}












