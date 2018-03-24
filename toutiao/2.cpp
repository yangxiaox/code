#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Node {
    int x, ans, y;
};

int main() {
    Node a1, a2;
    int n;
    cin >> n;
    a1.x = 1;
    a1.y = 1;
    a1.ans = 0;
    queue<Node> que;
    que.push(a1);
    while(!que.empty()) {
        a1 = que.front();
        que.pop();
        
        if(a1.x == n) {
            cout << a1.ans << endl;
            return 0;
        }
        
        if(a1.x + a1.y <= n) {
            a2.x = a1.x + a1.y;
            a2.ans = a1.ans + 1;
            a2.y = a1.y;
            que.push(a2);
        } 

        if(a1.x * 2 <= n) {
            a2.y = a1.x;
            a2.x = a1.x * 2;
            a2.ans = a1.ans + 1;
            que.push(a2);
        }
    }
}
