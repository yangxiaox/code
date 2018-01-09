/*************************************************************************
	> File Name: 17-10-22.4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月22日 星期日 16时14分59秒
 ************************************************************************/

#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

class Screen {
private:
  	unsigned int _width;
  	unsigned int _height;

  	Screen(unsigned int width, unsigned int height) {
    		_width = width;
    		_height = height;
  	};
  	Screen() {

  	}
  	~Screen() {
  		delete instance;
  	}
    static Screen* instance;
public:
  	//TODD
    static Screen* getInstance(unsigned int width = 1920, unsigned int height = 1080) {
        if (Screen::instance == nullptr) {
            if (width > 1920 || width <= 0) {
                width = 1920;
            }
            if (height > 1080 || height <= 0) {
                height = 1080;
            }
            Screen::instance = new Screen(width, height);
        }
        return Screen::instance;
    }
    //unsigned
    int getWidth() {
        return _width;
    }
    //unsigned
    int getHeight() {
        return _height;
    }
    Screen(const Screen&)=delete;
    Screen & operator= (const Screen&)=delete;
};

Screen* Screen::instance = nullptr;

int main() {
  	int width, height;
  	Screen* screen = 0;
  	cin >> width >> height;
  	screen = Screen::getInstance(width, height);
  	screen = Screen::getInstance();
  	cout << screen->getWidth() << " " <<
  		screen->getHeight() << endl;

  	return 0;
}
