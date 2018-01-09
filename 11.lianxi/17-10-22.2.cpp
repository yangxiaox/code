/*************************************************************************
	> File Name: 17-10-22.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月22日 星期日 14时49分28秒
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
    
    
    friend Complex operator+(const Complex& c1, const Complex& c2);
    friend Complex operator-(const Complex& c1, const Complex& c2);
    friend Complex operator*(const Complex& c1, const Complex& c2);
    //x=(ac+bd)/(c^2+d^2) y=(bc-ad)/(c^2+d^2)
    friend Complex operator/(const Complex& c1, const Complex& c2);
    
    friend istream &operator>>(istream& i, Complex& c);
    friend ostream &operator<<(ostream& i, const Complex& c);
};

Complex operator+(const Complex& c1, const Complex& c2) {
    Complex x;
    x.real = c1.real + c2.real;
    x.image = c1.image + c2.image;
    return x;
}
Complex operator-(const Complex& c1, const Complex& c2) {
    Complex x;
    x.real = c1.real - c2.real;
    x.image = c1.image - c2.image;
    return x;
}
Complex operator*(const Complex& c1, const Complex& c2) {
    Complex x;
    x.real = c1.real * c2.real - c1.image * c2.image;
    x.image = c1.image * c2.real + c1.real * c2.image;
    return x;
}
//x=(ac+bd)/(c^2+d^2) y=(bc-ad)/(c^2+d^2)
Complex operator/(const Complex& c1, const Complex& c2) {
    Complex x;
    x.real = (c1.real * c2.real + c1.image * c2.image) / (c2.real * c2.real + c2.image * c2.image);
    x.image = (c1.image * c2.real - c1.real * c2.image) / (c2.real * c2.real + c2.image * c2.image);
    return x;
}

istream& operator>>(istream& i, Complex& c) {
    return i >> c.real >> c.image;
}
ostream& operator<<(ostream& o, const Complex& c) {
    return o << "(" << c.real << (c.image >= 0 ? "+" : "") << c.image << "i)";
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
