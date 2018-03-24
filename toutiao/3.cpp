/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月24日 星期六 20时53分04秒
 ************************************************************************/

#include<iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

typedef long long ll;
const int inf = 0x3f3f3f3f;

ll cal_num(char *str, int st, int ed) {
    int priority = 0;
    int opt_num = 0;
    int cur_priority = 0, min_priority = inf, min_pos = -1;
    for (int i = st ; i < ed ; ++i) {
        if (str[i] == '+') cur_priority = priority + 1;
        else if (str[i] == '-') cur_priority = priority + 1;
        else if (str[i] == '*') cur_priority = priority + 2;
        else continue;
        ++opt_num;
        if (cur_priority <= min_priority) {
            min_priority = cur_priority;
            min_pos = i;
        }
    }
    if (opt_num == 0) {
        ll temp = 0;
        for (int i = st ; i < ed ; ++i) {
            if (str[i] < '0' || str[i] > '9') continue;
            temp = temp * 10 + (str[i] - '0');
        }
        return temp;
    }
    ll ta = cal_num(str, st, min_pos);
    ll tb = cal_num(str, min_pos + 1, ed);
    switch (str[min_pos]) {
        case '+' :
            return (ta + tb);
        case '-' :
            return (ta - tb);
        case '*' :
            return (ta * tb);
    }
    return 0;
}
void func(char n, int len) {
    switch (n) {
        case '-': {
            switch (len) {
                case 1:
                case 2:
                case 4:
                case 5:
                    cout << ".....";
                    break;
                case 3:
                    cout << "66666";
                    break;
            }
            break;
        }
        case '0': {
            switch (len) {
                case 1:
                case 5:
                    cout << "66666";
                    break;
                case 2:
                case 3:
                case 4:
                    cout << "6...6";
                    break;
            }
            break;
        }
        case '1': {
            cout << "....6";
            break;
        }
        case '2': {
            switch (len) {
                case 1:
                case 3:
                case 5:
                    cout << "66666";
                    break;
                case 2:
                    cout << "....6";
                    break;
                case 4:
                    cout << "6....";
                    break;
            }
            break;
        }
        case '3': {
            switch (len) {
                case 1:
                case 3:
                case 5:
                    cout << "66666";
                    break;
                case 2:
                case 4:
                    cout << "....6";
                    break;
            }
            break;
        }
        case '4': {
            switch (len) {
                case 1:
                case 2:
                    cout << "6...6";
                    break;
                case 3:
                    cout << "66666";
                    break;
                case 4:
                case 5:
                    cout << "....6";
                    break;
            }
            break;
        }
        case '5': {
            switch (len) {
                case 1:
                case 3:
                case 5:
                    cout << "66666";
                    break;
                case 4:
                    cout << "....6";
                    break;
                case 2:
                    cout << "6....";
                    break;
            }
            break;
        }
        case '6': {
            switch (len) {
                case 1:
                case 3:
                case 5:
                    cout << "66666";
                    break;
                case 2:
                    cout << "6....";
                    break;
                case 4:
                    cout << "6...6";
                    break;
            }
            break;
        }
        case '7': {
            switch (len) {
                case 2:
                case 3:
                case 4:
                case 5:
                    cout << "....6";
                    break;
                case 1:
                    cout << "66666";
                    break;
            }
            break;
        }
        case '8': {
            switch (len) {
                case 1:
                case 3:
                case 5:
                    cout << "66666";
                    break;
                case 2:
                case 4:
                    cout << "6...6";
                    break;
            }
            break;
        }
        case '9': {
            switch (len) {
                case 1:
                case 3:
                case 5:
                    cout << "66666";
                    break;
                case 2:
                    cout << "6...6";
                    break;
                case 4:
                    cout << "....6";
                    break;
            }
            break;
        }
    }
    return ;
}

int fpow(int a) {
    int x = 1;
    while (a--) {
        x *= 10;
    }
    return x;
}

int main() {
    char *str = (char *)malloc(100* sizeof(char));
    scanf("%s", str);
    long long ans = cal_num(str, 0, strlen(str));
    for (int i = 1; i <= 5; ++i) {
        int x = ans, y = 0;
        while (x != 0) {
            x /= 10;
            y++;
        }
        if (ans < 0) {
            x = -1 * ans;
            func('-', i);
            cout << "..";
        } else {
            x = ans;
        }
        while (y--) {
            int z = x / fpow(y);
            x %= 10;
            char c = z + 48;
            func(c, i);
            if (y != 0) {
                cout << "..";
            }
        }
        cout << endl;
    }
    return 0;
}
