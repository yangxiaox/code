/*************************************************************************
	> File Name: 16.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月30日 星期六 15时33分55秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
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
                if (this->s < a->s) {
                    return true;
                } else if (this->s == a->s) {
                    if (this->f == 0) {
                        return true;
                    }
                }
                return false;
            }
            return false;
        }
        return false;
    }
};

times **my_sort(times **temp) {
    for (int i = 1; i <= temp[0]->h; ++i) {
        int k = i;
        for (int j = i + 1; j <= temp[0]->h; ++j) {
            if (temp[j]->h < temp[k]->h) {
                k = j;
            } else if (temp[j]->h == temp[k]->h) {
                if (temp[j]->m < temp[k]->m) {
                    k = j;
                } else if (temp[j]->m == temp[k]->m) {
                    if (temp[j]->s < temp[k]->s) {
                        k = j;
                    }
                }
            }
        }
        if (k != i) {
            times *t = temp[i];
            temp[i] = temp[k];
            temp[k] = t;
        }
    }
    return temp;
}

times **run(times *stand, pair<times *, times*> range) {
    int sysmmetric = (stand->h * 3600 + stand->m * 60 + stand->s) * 30 * 2;
    times *int_temp = new times;
    int_temp->h = (sysmmetric / 108000) % 12;
    int_temp->m = (sysmmetric % 108000) / 23400;
    int_temp->s = ((sysmmetric % 108000) % 23400) / 390;
    int_temp->f = (((sysmmetric % 108000) % 23400) % 390) / 30;
    int i = 0;
    times **ret = (times **)malloc(sizeof(times *) * 14);
    ret[0] = (times *)malloc(sizeof(times));
    ret[0]->h = 0;
    while (i++ <= 12) {
        if (range.first->operator<=(int_temp) && int_temp->operator<=(range.second)) {
            times *temp = new times(int_temp->h, int_temp->m, int_temp->s, int_temp->f);
            ret[++(ret[0]->h)] = temp;
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
        (int_temp->f)++;
        if (int_temp->f == 13) {
            int_temp->f = 0;
            int_temp->s++;
            if (int_temp->s == 60) {
                int_temp->s = 0;
                int_temp->m++;
                if (int_temp->m == 60) {
                    int_temp->m = 0;
                    int_temp->h++;
                    if (int_temp->h == 12) {
                        int_temp->h = 0;
                    }
                }
            }
        }
        //int_temp->s = ((int_temp->s - 37) < 0 ? (flag = 1, int_temp->s + 23) : int_temp->s - 37);
        //int_temp->m = ((int_temp->m - 4 - flag) < 0 ? (int_temp->m + 56 - flag, flag = 1) : (int_temp->m - 4, flag = 0));
        //int_temp->h = ((int_temp->h + 1 - flag) >= 12 ? 0 : int_temp->h + 1 - flag);
    }
    ret = my_sort(ret);
    //cout << ret[0]->h << endl;
    //for (int i = 1; i <= ret[0]->h; ++i) {
    //    cout << "time = " << ret[i]->h << ":" << ret[i]->m << ":" << ret[i]->s << " " << ret[i]->f << "/13" << endl;
    //}
    return ret;
}

int main() {
    int n;
    cin >> n;
    int iters = 1;
    while (iters++ <= n) {
        times *stand = new times();
        times *left = new times();
        times *right = new times();
        scanf("%d:%d:%d", &stand->h, &stand->m, &stand->s);
        scanf("%d:%d:%d", &left->h, &left->m, &left->s);
        scanf("%d:%d:%d", &right->h, &right->m, &right->s);
        times **temp = run(stand, {left, right});
        
        printf("Case %d: %d\n", iters - 1, temp[0]->h);
        for (int iter = 1; iter <= temp[0]->h; ++iter) {
            printf("%02d:%02d:%02d", temp[iter]->h, temp[iter]->m, temp[iter]->s);
            //cout << iter->h << ":" << iter->m << ":" << iter->s;
            if (temp[iter]->f != 0) {
                printf(" %d/13\n", temp[iter]->f);
            } else {
                printf("\n");
            }
        }
    }


    return 0;
}
