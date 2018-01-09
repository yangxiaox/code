/*************************************************************************
	> File Name: 17-10-22.3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月22日 星期日 15时14分45秒
 ************************************************************************/

#include <iostream>
using namespace std;
class Complex
{
private:
    double real;
    double image;
public:
    Complex(const Complex& complex) :real{ complex.real }, image{ complex.image } {
    }
    Complex(double Real=0, double Image=0) :real{ Real }, image{ Image } {
    }
    friend istream &operator>>(istream &in, Complex &c);
    friend ostream &operator<<(ostream &out, const Complex &c);
    friend Complex operator+(const Complex &a, const Complex &b);
    friend Complex operator-(const Complex &a, const Complex &b);
    friend Complex operator*(const Complex &a, const Complex &b);
    friend Complex operator/(const Complex &a, const Complex &b);
};
 
Complex operator+(const Complex &a, const Complex &b) {
    Complex c;
    c.real = a.real + b.real;
    c.image = a.image + b.image;
    return c;
}
 
Complex operator-(const Complex &a, const Complex &b) {
    Complex c;
    c.real = a.real - b.real;
    c.image = a.image - b.image;
    return c;
}
 
Complex operator*(const Complex &a, const Complex &b) {
    Complex c;
    c.real = a.real * b.real - a.image * b.image;
    c.image = a.real * b.image + a.image * b.real;
    return c;
}
 
Complex operator/(const Complex &a, const Complex &b) {
    Complex c;
    double t = b.real * b.real + b.image * b.image;
    c.real = a.real * b.real + a.image * b.image;
    c.image =  a.image * b.real - a.real * b.image;
    c.real /= t;
    c.image /= t;
    return c;
}
 
istream &operator>>(istream &in, Complex &c) {
    return in >> c.real >> c.image;
}
 
ostream &operator<<(ostream &out, const Complex &c) {
    out << "(" << c.real;
    if (c.image >= 0) {
        out << "+";
    }
    return out << c.image << "i)";
}
 
int main() {
    Complex z1, z2;
    cin >> z1;
    cin >> z2;
    cout << z1 << " " << z2 << endl;
    cout << z1 + z2 << endl;
    cout << z1 - z2 << endl;
    cout << z1*z2 << endl;
    cout << z1 / z2 << endl;
    return 0;
}
