/*************************************************************************
	> File Name: 17-11-9.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月09日 星期四 11时17分55秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct Matrix {
    int **data;
    int size;
};

void init_3(Matrix *m) {
    m->data[0][0] = 0;
    m->data[0][1] = 1;
    m->data[0][2] = 0;
    m->data[1][0] = 2;
    m->data[1][1] = 0;
    m->data[1][2] = 1;
    m->data[2][0] = 3;
    m->data[2][1] = 0;
    m->data[2][2] = 0;
    return ;
}

Matrix *init(int n) {
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    m->data = (int **)malloc(sizeof(int *) * 3);
    for (int i = 0; i < 3; ++i) {
        m->data[i] = (int *)calloc(3, sizeof(int));
    }
    m->size = n;
    return m;
}

void clear(Matrix *m) {
    for (int i = 0; i < m->size; ++i) {
        free(m->data[i]);
    }
    free(m);
    return ;
}

Matrix *power(Matrix *m1, Matrix *m2) {
    Matrix *m = init(m1->size);
    for (int i = 0; i < m1->size; ++i) {
        for (int j = 0; j < m1->size; ++j) {
            for (int k = 0; k < m1->size; ++k) {
                m->data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
            m->data[i][j] %= 9973;
        }
    }
    clear(m1);
    return m;
}

int func(int n) {
    Matrix *m = init(3);
    m->data[0][0] = 7;
    m->data[0][1] = 3;
    m->data[0][2] = 1;
    if (n <= 3 && n > 0) return m->data[0][3 - n];
    Matrix *base = init(3);
    init_3(base);
    n -= 3;
    while (n) {
        if (n & 1) {
            m = power(m, base);
           // m->data[0][0] %= 9973;
           // m->data[0][1] %= 9973;
           // m->data[0][2] %= 9973;
        }
        base = power(base, base);
        n >>= 1;
    }
    int x = m->data[0][0];
    clear(m);
    clear(base);
    return x;
}

int main() {
    int n;
    cin >> n;
    cout << func(n) << endl;
    return 0;
}
