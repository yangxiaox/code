/*************************************************************************
	> File Name: 16.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月30日 星期六 15时33分55秒
 ************************************************************************/

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

class times {
public:
    times(int h = 0, int m = 0, int s = 0, int f = 0) : h(h), m(m), s(s), f(f) {}
    ~times() = default;
    int h, m, s;
    int f;
    bool operator<=(times *a) {
        //cout << "this = " << this->h << ":" << this->m << ":" << this->s << endl;
        //cout << "a = " << a->h << ":" << a->m << ":" << a->s << endl;
        if (this->h < a->h) {
            return true;
        } else if (this->h == a->h) {
            if (this->m < a->m) {
                return true;
            } else if (this->m == a->m) {
                if (this->s <= a->s) {
                    return true;
                }
                return false;
            }
            return false;
        }
        return false;
    }
};

vector<shared_ptr<times> > run(shared_ptr<times> stand, pair<shared_ptr<times>, shared_ptr<times> > range) {
    int sysmmetric = (stand->h * 3600 + stand->m * 60 + stand->s) * 30 * 2;
    shared_ptr<times> int_temp = make_shared<times>();
    int_temp->h = (sysmmetric / 108000) % 12;
    int_temp->m = (sysmmetric % 108000) / 23400;
    int_temp->s = ((sysmmetric % 108000) % 23400) / 390;
    int i = 0;
    int f = 0;
    vector<shared_ptr<times> > ret;
    while (i++ <= 12) {
        if (range.first->operator<=(int_temp.get()) && int_temp->operator<=(range.second.get())) {
            shared_ptr<times> temp = make_shared<times>(int_temp->h, int_temp->m, int_temp->s, f);
            ret.push_back(temp);
        }
        int flag = 0;
        int s = int_temp->s - 37;
        if (s < 0) {
            flag = 1; 
            s = int_temp->s + 23;
        }
        int_temp->s = s;
        int m = int_temp->m - 4 - flag;
        if (m < 0) {
            m = int_temp->m + 56 - flag;
            flag = 1;
        } else {
            flag = 0;
        }
        int_temp->m = m;
        int_temp->h = ((int_temp->h + 1 - flag) >= 12 ? 0 : int_temp->h + 1 - flag);
        f++;
        //int_temp->s = ((int_temp->s - 37) < 0 ? (flag = 1, int_temp->s + 23) : int_temp->s - 37);
        //int_temp->m = ((int_temp->m - 4 - flag) < 0 ? (int_temp->m + 56 - flag, flag = 1) : (int_temp->m - 4, flag = 0));
        //int_temp->h = ((int_temp->h + 1 - flag) >= 12 ? 0 : int_temp->h + 1 - flag);
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    int iter = 1;
    while (iter++ <= n) {
        shared_ptr<times> stand = make_shared<times>();
        shared_ptr<times> left = make_shared<times>();
        shared_ptr<times> right = make_shared<times>();
        scanf("%d:%d:%d", &stand->h, &stand->m, &stand->s);
        scanf("%d:%d:%d", &left->h, &left->m, &left->s);
        scanf("%d:%d:%d", &right->h, &right->m, &right->s);
        vector<shared_ptr<times> > temp = run(stand, {left, right});

        printf("Case %d: %d\n", iter - 1, (int)temp.size());
        for (auto iter : temp) {
            printf("%02d:%02d:%02d", iter->h, iter->m, iter->s);
            //cout << iter->h << ":" << iter->m << ":" << iter->s;
            if (iter->f != 0) {
                cout << " " << iter->f <<"/13" << endl;
            } else {
                cout << endl;
            }
        }
    }


    return 0;
}
