#include "Array.h"
#include <stdio.h>
#include <iostream>



int main() {
	//mciSendString(L"open C:/1.mp3", NULL, 0, 0);
	//mciSendString(L"play C:/1.mp3 ", NULL, 0, 0);
	//Sleep(1000);
	//mciSendString(L"close C:/1.mp3 ", NULL, 0, 0);
	//mciSendString(L"open C:/2.mp3", NULL, 0, 0);
	//mciSendString(L"play C:/2.mp3 ", NULL, 0, 0);
	my_vector<int> vec(2);
	my_vector<int> vec2(1);
	for (int i = 0; i < 10; ++i) {
		vec.push_back(i);
	}
	for (int i = 10; i < 20; ++i) {
		vec2.push_back(i);
	}
	vec2.out();
	//my_vector<int> vec3();
	
	//(vec + vec2).out();

	//int data[4] = { 1,2,5,6 };
	//int n = 4;
	//for (int i = 0; i < 7; ++i) {
	//	int k = 0;
	//	while (k < n) {
	//		for (int j = 0; j < 4; ++j) {
	//			std::cout << p[data[k]][i][j] << " ";
	//		}
	//		std::cout << " ";
	//		k++;
	//	}
	//	std::cout << std::endl;

	//}


	return 0;

}
