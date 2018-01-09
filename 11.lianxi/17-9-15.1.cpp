/*************************************************************************
	> File Name: 17-9-15.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月15日 星期五 18时12分33秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

char *no_repeat(string str) {
    int ch[26] = {0};
    int s1 = 0, s2 = 0;
    int len = 0, x, y;
    for (; s1 < str.length(); ++s1) {
        ch[str[s1] - 'A']++;
        if (ch[str[s1] - 'A'] == 2) {
            for (; s2 <= s1; ++s2) {
                ch[str[s2] - 'A']--;
                if (ch[str[s2] - 'A']) {
                    ++s2;
                    break;
                }
            }
        }
        if ((s1 - s2) > len) {
            len = s1 - s2;
            x = s2; 
            y = s1;
        }
    }
    char *buffer = (char *)malloc(sizeof(char) * (y - x + 2));
    str.copy(buffer, (y - x + 1), x);
    buffer[y - x + 1] = '\0';
    return buffer;
}

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    cout << no_repeat(str) << endl;
    return 0;
}
