/*************************************************************************
	> File Name: 17-9-9.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月09日 星期六 08时55分09秒
 ************************************************************************/


/*************************************************************************
 *
 *     > File Name: RVO
 *
 *         > Author:    hug
 *
 *             > Mail:      hug@haizeix.com
 *
 *                 > Created Time: 六  9/ 9 08:54:46 2017
 *
 *                 ************************************************************************/

  

#include <iostream>
#include <string>
using namespace std;

class People {
    public :
    People(string x);
    People(const People &a);
    ~People();
    void out();
    People operator= (People a) {
        a.x = "error";
        cout << this << " operator1= is called" << endl;
        cout << &a << " is __a address" <<endl;
        int x = 10;
        cout << &x << "is x address" << endl;
        return a;
    }
    int operator= (const int x) {
        if (x == 1) {
            this->x = "100";
        } else {
            this->x = "200";
        }
        cout << this << " operator2= is called" << endl;
        return 256;
    }
    private :
    string x;
};

People func() {
    //int x[100];
    //cout << x << " address is x !" << endl;
    int x = 0;
    People temp("test");
    int y = 0;
    return temp;
}

int main() {
    People a("hug");
    // a = (a = b);
    People b(a = func());
    cout << &b << " is b address" << endl;
    //Perple __yyy = a.operator(Perple __xxx = func());
    return 0;
}

People::People(string x) : x(x) {
    cout << "constructor by " << this << endl;
}

People::People(const People &a) {
    this->x = a.x + "0";
    cout << "copy contructor called from " << &a << " to " << this << endl;
}

People::~People() {
    cout << this << " destroy" << endl;
}

void People::out() {
    cout << this << " name is " << this->x << endl;
    return ;
}
             
