/*************************************************************************
	> File Name: 13.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月24日 星期日 16时18分25秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

int main() {
    shared_ptr<vector<string> > p;
    cout << (p.get() == nullptr) << endl;
    p = make_shared<vector<string> >();
    p->push_back("123");
    p->push_back("456");
    p->push_back("789");
    for (int i = 0; i < p->size(); ++i) {
        cout << (*p)[i] << " " << endl; 
    }
    return 0;
}
