#include <iostream>
#include <string>

#include "Array.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;




int main() {
	string oper;
	int n, temp;
	my_vector<int> vec1, vec2, vec3;
    cout << "please cin vector1 of size :" << endl;
	cin >> n;
	while (n--) {
		cin >> temp;
		vec1.push_back(temp);
	}
    cout << "please cin vector2 of size:" << endl;
	cin >> n;
	while (n--) {
		cin >> temp;
		vec2.push_back(temp);
	}
	if (vec1 == vec2) {
		cout << "vector1 == vector2" << endl;
	}
	else {
		cout << "vector1 != vector2" << endl;
	}
	cout <<"vec3 = vec1 + vec2  , out vec3" <<endl;
	vec3 = vec1 + vec2;
	vec3.out();

	cout << "buling buling" << endl;
    	


	return 0;

}
