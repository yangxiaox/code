/*************************************************************************
	> File Name: 10.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月19日 星期日 16时02分05秒
 ************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;

void my_sort(char *str, int left, int right) {
    if (left >= right) {
        return ;
    }
    char c = str[left];
    int l = left, r = right;
    while (l < r) {
        while (l < r && str[r] >= c) r--;
        if (l < r) str[l] = str[r];
        while (l < r && str[l] <= c) l++;
        if (l < r) {
            str[r] = str[l];
        }
    }
    str[l] = c;
    my_sort(str, left, l - 1);
    my_sort(str, l + 1, right);
    return ;
}

int main() {
    //char *str = (char *)malloc(sizeof(char) * 110005);
    char str[110005];
    char str2[110005];
    cin >> str;
    int len = strlen(str);
    cout << len << endl;
    for (int i = 0; i < len; ++i) {
        str2[i] = str[i];
    }
    my_sort(str2, 0, len - 1);
    int index[26] = {0};
    for (int i = len - 1; i > 0; --i) {
        if (index[str2[i] - 'a'] == 0) {
            index[str2[i] - 'a'] = i; 
        }
    }
    str2[len - 1] = '\0';
    str2[len - 2] = str[0];
    int i = len - 3;
    while (i >= 0) {
        str2[i] = str[index[str2[i + 1] - 'a']];
        index[str2[i + 1] - 'a']--;
        i--;
    }
    cout << str2 << endl;
    return 0;
}
