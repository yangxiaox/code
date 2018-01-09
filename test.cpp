#include "Array.h"
#include <stdio.h>
#include <iostream>



int main() {
	my_vector<int> vec(2);
	my_vector<int> vec2(1);
	my_vector<int> vec3;
    for (int i = 123456789; i < 912345678;) {
		vec.push_back(i);
        int x = i / 100000000;
        i = (i % 100000000) * 10 + x;
	}
    int x = 0;
	for (int i = 1; i <= 10; ++i) {
        x = x * 10 + i;
        if (i == 10) {
            x -= 10;
        }
		vec2.push_back(x);
	}
    vec3 = vec + vec2;
    vec3.out();
	return 0;

}
