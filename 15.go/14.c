/*************************************************************************
	> File Name: 14.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月22日 星期三 20时08分21秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct my_str {
    char c;
    char *current, *past;
} my_str;

char *time_current(char *a, char *b) {
    if (a[0] == '0') {
        return "0";
    }
    if (a[0] == '1') {
        if (b[0] != '0') {
            return b;
        } else {
            return "1";
        }
    }
    if (a[0] == 'n') {
        if (b[0] != 'n') {
            return a;
        }
        int i = 2, x = 0, y = 0;
        while (a[i]) {
            x = x * 10 + a[i] - '0';
            ++i;
        }
        i = 2;
        while (b[i]) {
            y = y * 10 + b[i] - '0';
            ++i;
        }
        x += y;
        y = 0;
        while (x) {
            y = y * 10 + (x % 10);
            x /= 10;
        }
        char *str = (char *)malloc(sizeof(char) * 10);
        str[0] = 'n';
        str[1] = '^';
        i = 2;
        while (y) {
            str[i++] = (y % 10) + '0';
            y /= 10;
        }
        str[i] = '\0';
        return str;
    }
}

char *time_this(char *a, char *b) {
    if (a[0] == 'n' && b[0] == 'n') {
        return "1";
    }
    if (a[0] == 'n') {
        return "0";
    }
    if (b[0] == 'n') {
        return "n^1";
    }
    int i = 0, x = 0, y = 0;
    while (a[i]) {
        x = x * 10 + a[i] - '0';
        ++i;
    }
    i = 0;
    while (b[i]) {
        y = y * 10 + b[i] - '0';
        ++i;
    }
    if (a > b) {
        return "0";
    } else {
        return "1";
    }
}

int time_max(char *a, char *b) {
    if ((a[0] == '0' && b[0] == '0') || (a[0] == '1' && b[0] == '1')) {
        return 0;
    }
    if (a[0] == '0') {
        return 0;
    }
    if (b[0] == '0') {
        return 1;
    }
    if (a[0] == '1') {
        return 0;
    }
    if (b[0] == '1') {
        return 1;
    }
    if (strlen(a) > strlen(b)) return 1;
    if (strlen(a) < strlen(b)) return 0;
    return strcmp(a, b) > 0 ? 1 : 0;
}


int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        my_str *ms = (my_str *)malloc(sizeof(my_str) * 100);
        int top = 0;
        
        int var[26];
        memset(var, 0, 26);
        
        int flag = 1;
        int n;
        char *time = (char *)malloc(sizeof(char) * 10);
        char *str = (char *)malloc(sizeof(char) * 10);
        char c;
        scanf("%d%c", &n, &c);
        scanf("%s", time);
        for (int i = 0; i < n; ++i) {
            getchar();
            scanf("%[^\n]s", str);
            if (str[0] == 'F') {
                if (var[str[2] - 'a'] == 1) {
                    flag = 0;
                }
                var[str[2] - 'a']++;
                char temp[2][3];
                int k = 4, l = 0;
                while (str[k] != ' ') {
                    temp[0][l++] = str[k];
                    k++;
                }
                l = 0;
                while (str[++k] != '\0') {
                    temp[1][l++] = str[k];
                }
                my_str my_temp;
                my_temp.past = my_temp.current = time_this(temp[0], temp[1]);
                my_temp.c = str[2];
                ms[top++] = my_temp;
            } else {
                var[ms[--top].c - 'a']--;
                if (top != 0) {
                    ms[top - 1].past = time_max(ms[top - 1].past, time_current(ms[top - 1].current, ms[top].past)) ? ms[top - 1].past : time_current(ms[top - 1].current, ms[top].past);
                }
            }
        }
        if (!flag || top != 0) {
            printf("ERR\n");
            continue;
        }
        for (int i = 0; ms[0].past[i]; ++i) {
            if (time[i + 2] != ms[0].past[i]) {
                printf("No\n");
                continue;
            }
        }
        printf("Yes\n");
    }
    
    
    
    
    
    return 0;
}
