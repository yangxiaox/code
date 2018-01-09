/*************************************************************************
	> File Name: 17-9-7.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年09月07日 星期四 18时36分06秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Day {

};

class Location {

};

class People {
public :
    People(const People &a) {
        this->__name = a.__name + "2";
        cout << "copy constructor" << endl;
    }
    People() {};
    People(const string &__name) {
        this->__name = __name;
    }
    void say(string word) {
        cout << this->__name << " say : "<< word << endl;
    }
    void set_name(string __name) {
        this->__name = __name;
    }
private :
    string __name;
};

int main() {
    string a;
    cin >> a;
    People hh(a);
    hh.say("bulingbuling");
    People hug("haha");
    hug.set_name("chuanzhang");
    hug.say("I love haizei !");
    return 0;
}
