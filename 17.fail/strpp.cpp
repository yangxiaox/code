/*************************************************************************
	> File Name: strpp.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月19日 星期日 10时39分15秒
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;

void get_next(char *t, int *next) {
    next[0] = -1;
    int i = 1, match = -1;
    while (t[i]) {
        while (match != -1 && t[match + 1] != t[i]) {
            match = next[match];
        }
        if (t[match + 1] == t[i]) {
            next[i] = match + 1;
            match++;
        } else {
            next[i] = -1;
        }
        i++;
    }
    return ;
}

int KMP(char *s, char *t, int *next) {
    int i = 0, j = -1;
    while (s[i]) {
        while (j != -1 && t[j + 1] != s[i]) {
            j = next[j];
        }
        if (t[j + 1] == s[i]) {
            j++;
        }
        if (t[j + 1] == '\0') {
            return 1;
        }
        i++;
    }
    return 0;
}

int shift_and(char *s, char *t) {
    int str[256] = {0};
    int len = 0, p = 0;
    for (int i = 0; t[i]; ++i) {
        str[t[i]] |= (1 << i);
        len++;
    }
    for (int i = 0; s[i]; ++i) {
        p = (p << 1 | 1) & str[s[i]];
        if (p & (1 << (len - 1))) {
            return 1;
        }
    }
    return 0;
}

int sunday(char *s, char *t) {
    int str[256] = {0};
    int t_len = strlen(t);
    int s_len = strlen(s);
    for (int i = 0; i < 256; ++i) {
        str[i] = t_len + 1;
    }
    for (int i = 0; t[i]; ++i) {
        str[t[i]] = t_len - i;
    }
    int i = 0, j = 0;
    while (i + t_len <= s_len) {
        if (s[i + j] != t[j]) {
            i += str[s[i + t_len]];
            j = 0;
        } else {
            ++j;
        }
        if (t[j] == '\0') {
            return 1;
        }
    }
    return 0;
}

int main() {
    int next[100];
    char s[100], t[100];
    cin >> s >> t;
    get_next(t, next);
    cout << "KMP: " << KMP(s, t, next) << endl;
    cout << "shift_and: " << shift_and(s, t) << endl;
    cout << "sunday: " << sunday(s, t) << endl;



    return 0;
}
