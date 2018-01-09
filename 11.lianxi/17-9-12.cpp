/*************************************************************************
	> File Name: 17-9-12.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月12日 星期二 18时25分51秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Animal {
public :
    Animal(string name) : __name(name) {}
    Animal() {}
    void set_name(string name) {
        this->__name = name;
    }
    void tell_me_your_name() {
        cout << "my name is : " << this->__name << endl;
    }
protected :
    string __name;
};

class Cat : public Animal {
public :
    Cat () {}
    Cat(string name) : Animal(name) {}
    void tell_me_your_name() {
        cout << "cat name is : " << this->__name << endl;
    }
private :
    int tail;
};

class HasTailCat : public Cat {
public:
    HasTailCat(string name) : Cat(name) {}
};

int main() {
    HasTailCat a("garfiled");
    a.set_name("haha");
    a.tell_me_your_name();

    return 0;
}
