#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
const int maxn = 1e5+10;
const int inf = 0x3f3f3f3f;

char str[maxn];
string s[10];

void print_num(int x) {
    switch(x) {
        case 0:{
            s[1] += "66666";
            s[2] += "6...6";
            s[3] += "6...6";
            s[4] += "6...6";
            s[5] += "66666";
        } break;
        case 1:{
            s[1] += "....6";
            s[2] += "....6";
            s[3] += "....6";
            s[4] += "....6";
            s[5] += "....6";
        } break;
        case 2:{
            s[1] += "66666";
            s[2] += "....6";
            s[3] += "66666";
            s[4] += "6....";
            s[5] += "66666";
        } break;
        case 3:{
            s[1] += "66666";
            s[2] += "....6";
            s[3] += "66666";
            s[4] += "....6";
            s[5] += "66666";
        } break;
        case 4:{
            s[1] += "6...6";
            s[2] += "6...6";
            s[3] += "66666";
            s[4] += "6....";
            s[5] += "6....";
        } break;
        case 5:{
            s[1] += "66666";
            s[2] += "6....";
            s[3] += "66666";
            s[4] += "....6";
            s[5] += "66666";
        } break;
        case 6:{
            s[1] += "66666";
            s[2] += "6...,";
            s[3] += "66666";
            s[4] += "6...6";
            s[5] += "66666";
        } break;
        case 7:{
            s[1] += "66666";
            s[2] += "....6";
            s[3] += "....6";
            s[4] += "....6";
            s[5] += "....6";
        } break;
        case 8:{
            s[1] += "66666";
            s[2] += "6...6";
            s[3] += "66666";
            s[4] += "6...6";
            s[5] += "66666";
        } break;
        case 9:{
            s[1] += "66666";
            s[2] += "6...6";
            s[3] += "66666";
            s[4] += "....6";
            s[5] += "66666";
        } break;
    }

            s[1] += "..";
            s[2] += "..";
            s[3] += "..";
            s[4] += "..";
            s[5] += "..";

    return ;
}


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

int main() {
        for(int i = 0; i < 9; i++) {
            s[i] = "";
        }
        scanf("%s", str);
        long long ans = cal_num(str, 0, strlen(str));
            if(ans == 0)
            print_num(0);
        else {
            long long temp = 0;
            while(ans) {
                temp = temp * 10 + ans%10;
                ans/=10;
            }
            while(temp) {
                print_num(temp%10);
                temp/=10;
            }
            
        }

        for(int i = 1; i <= 5; i++) {
            cout << s[i] << endl;
        }
    return 0;
}
