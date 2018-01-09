/*************************************************************************
	> File Name: leetcode_128.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月05日 星期日 08时44分32秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct UnionSet {
    int *father, *size;
    int n;
} UnionSet;

typedef struct HashData {
	int val, ind;
	int flag;
} HashData;

typedef struct HashTable {
	HashData *data;
	int size;
} HashTable;

UnionSet *init(int n);
void clear(UnionSet *u);
int find(UnionSet *u, int val);
int merge(UnionSet *u, int p, int q);

HashTable *init_hash(int n);
void clear_hash(HashTable *ht);
int hash_func(int ind);
int insert(HashTable *ht, HashData hd);
int search(HashTable *ht, int val);

int main() {
    return 0;
}

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->father = (int *)malloc(sizeof(int) * n);
    u->size = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        u->father[i] = i;
        u->size[i] = 1;
    }
    u->n = n;
    return u;

}
void clear(UnionSet *u) {
    free(u->father);
    free(u->size);
    free(u);
    return ;
}
int find(UnionSet *u, int val) {
    if (u->father[val] == val) {
        return val;
    }
    u->father[val] = find(u, u->father[val]);
    return u->father[val];
}
int merge(UnionSet *u, int p, int q) {
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
    u->size[father_q] += u->size[father_p];
    return 1;
}

HashTable *init_hash(int n) {
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    ht->data = (HashData *)malloc(sizeof(HashData) * n);
    ht->size = n;
    return ht;
}
void clear_hash(HashTable *ht) {
    free(ht->data);
    free(ht);
}
int hash_func(int ind) {
    return ind & 0x7fffffff;
}
int insert(HashTable *ht, HashData hd) {
    int ind = hash_func(hd.val) % ht->size;
	int times = 1;
	while (ht->data[ind].flag && ht->data[ind].val != hd.val) {
		ind += times * times;
		ind %= ht->size;
		times++;
	}
	if (ht->data[ind].flag) return 0;
	ht->data[ind] = hd;
	return 1;
}
int search(HashTable *ht, int val) {
    int ind = hash_func(val) % ht->size;
	int times = 1;
	while (ht->data[ind].flag && ht->data[ind].val != val) {
		ind += times * times;
		ind %= ht->size;
		times++;
	}
	if (ht->data[ind].flag == 0) return -1;
	return ht->data[ind].ind;
}

