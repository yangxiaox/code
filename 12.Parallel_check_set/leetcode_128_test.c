/*************************************************************************
	> File Name: leetcode_128_test.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月07日 星期二 10时31分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Union {
    int *father, *size;
    int max_size;
} Union;

typedef struct Hash_data {
    int val, ind;
    int flag;
} Hash_data;

typedef struct Hash_table {
    Hash_data *data;
    int size;
} Hash_table;

Union *init(int n);
void clear(Union *u);
int find(Union *u, int ind);
int merge(Union *u, int p, int q);

Hash_table *init_hash(int n);
void clear_hash(Hash_table *ht);
int hash_func(int val);
int insert(Hash_table *ht, Hash_data hd);
int search(Hash_table *ht, int val);


Union *init(int n) {
    Union *u = (Union *)malloc(sizeof(Union));
    u->father = (int *)malloc(sizeof(int) * n);
    u->size = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        u->father[i] = i;
        u->size[i] = 1;
    }
    u->max_size = n > 0 ? 1 : 0;
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
    u->size[father_q] += u->size[father_p];
    if (u->size[father_q] > u->max_size) {
        u->max_size = u->size[father_q];
    }
    return 1;
}

Hash_table *init_hash(int n) {
    Hash_table *ht = (Hash_table *)malloc(sizeof(Hash_table));
    ht->data = (Hash_data *)calloc(n, sizeof(Hash_data));
    ht->size = n;
    return ht;
}
void clear_hash(Hash_table *ht) {
    free(ht->data);
    free(ht);
    return ;
}
int hash_func(int val) {
    return val & 0x7fffffff;
}
int insert(Hash_table *ht, Hash_data hd) {
    int ind = hash_func(hd.val);
    ind %= ht->size;
    int time = 1;
    while (ht->data[ind].flag && ht->data[ind].val != hd.val) {
        ind += time *time;
        ind %= ht->size;
        time++;
    }
    if (ht->data[ind].flag) return 0;
    ht->data[ind] = hd;
    return 1;
}
int search(Hash_table *ht, int val) {
    int ind = hash_func(val);
    ind %= ht->size;
    int time = 1;
    while (ht->data[ind].flag && ht->data[ind].val != val) {
        ind += time * time;
        ind %= ht->size;
        time++;
    }
    if (!ht->data[ind].flag) return -1;
    return ht->data[ind].ind;
}

int longestConsecutive(int* nums, int numsSize) {
    Union *u = init(numsSize);
    Hash_table *ht = init_hash(numsSize * 10);
    for (int i = 0; i < numsSize; ++i) {
        Hash_data hd = {nums[i], i, 1};
        if (!insert(ht, hd)) {
            continue;
        }
        int ind1 = search(ht, nums[i] + 1);
        int ind2 = search(ht, nums[i] - 1);
        if (ind1 != -1) {
            merge(u, i, ind1);
        }
        if (ind2 != -1) {
            merge(u, i, ind2);
        }
    }
    int num = u->max_size;
    clear(u);
    clear_hash(ht);
    return num;
}
