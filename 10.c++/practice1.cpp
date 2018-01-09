/*************************************************************************
	> File Name: practice1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月05日 星期二 18时42分00秒
 ************************************************************************/

#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::queue;
using std::stack;
//using std::unordered_map;
using namespace std;

int main() {
    unordered_map<string, double> h;
    string opr;
    while (cin >> opr) {
        if (opr == "push") {
            string name;
            double height;
            cin >> name >> height;
            h[name] = height;
        } else if (opr == "search") {
            string name;
            cin >> name;
            if (h.find(name) == h.end()) {
                cout << "oh no : " << name << " isn`t int hashtable!" << endl;
            } else {
                cout << h[name] << endl;
            }
        } else if (opr == "end") {
            break;
        }
    }
    return 0;
}
