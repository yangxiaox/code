/*************************************************************************
	> File Name: 17-9-16.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月16日 星期六 08时23分37秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Animal {
public :
    Animal(){
        cout << "default constructor" << endl;
    }
    //Animal(const string &name) : __name(name) {}
    Animal(const Animal &a) : __name(a.__name) {
        cout << "copy constructor" << endl;
    }
    void out() {
        cout << "my name is : " << this->__name << endl;
    }
    void set(const string &name) {
        this->__name = name;
    }
    virtual void run(){
        cout << "I don`t know" << endl;
    };
protected:
    string __name;
//__name
};

class tail {
public :
    tail() {
        cout << "tail constructor" << endl;
    }
    ~tail() {
        cout << "tail destruc" << endl;
    }
};

class objest {
public :
    virtual void run() {
        cout << "I arr" << endl;
    }
};

class Cat : public Animal, public objest{
public:
    Cat(){
        //cout << "Cat constructor" << endl;
    }
    ~Cat() {
        //cout << "Cat destruc" << endl;
    }
    Cat(const Cat &b) : Animal(b) {}
    Cat& operator=(const Cat &b) {
        this->Animal::operator=(b);
        //this->__name = b.__name;
        return *this;
    }
    void run () override {
        cout << "I can run with four legs" << endl;
    }
    //tail t;
};



int main() {
    //Cat a;
    //a.set("garfiled");
    //Cat b;
    //b = a;
    //a.out();
    //b.out();
    Cat a;
    objest &b = a;
    //Animal &b = a;
    //Animal *c = &a;
    a.run();
    b.run();
    //b.run();
    //c->run();
    return 0;
}
