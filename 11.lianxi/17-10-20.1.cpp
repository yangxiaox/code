/*************************************************************************
	> File Name: 17-10-20.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月20日 星期五 16时40分08秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct A
{
    int data;

    A(int theData)
        :data{ theData }
    {
    }
};

struct B : virtual A
{
    B() :A{ 1 }
    {
        cout << "B : " << data << endl;
    }
};

struct C : virtual A
{
    C() :A{ 2 }
    {
        cout << "C : " << data << endl;
    }
};

struct D : B, C
{
    D() :A{ 3 }
    {
        cout << "D : " << data << endl;
    }
};

int main()
{
    D d;
    cout << d.data << endl;
    return 0;
}
