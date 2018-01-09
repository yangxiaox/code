/*************************************************************************
	> File Name: 12.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月24日 星期日 10时00分56秒
 ************************************************************************/


#include <iostream>
#include <cstdio>
#include <algorithm>

using std::cout;
using std::endl;

template<typename T>
struct shared_ptr {
  shared_ptr() : obj(nullptr), cnt(nullptr) {}
  shared_ptr(const shared_ptr<T> &b) {
    this->obj = b.obj;
    this->cnt = b.cnt;
    if (this->cnt != nullptr) {
      *(this->cnt)++;
    }
  }
  shared_ptr(T *obj) {
    this->obj = obj;
    if (this->obj) {
      //this->cnt = new int;
      this->initcnt();
      this->setCnt(1);
    }
  }

  ~shared_ptr() {
    this->judgeDelete();
  }

  T *operator->() { return this->obj; }

  template<typename U>
  shared_ptr<T> &operator=(const shared_ptr<U> &b) {
//    if (this->obj != nullptr) {
//      this->Decrease();
//    }
    if ((void *)(this) == (void *)(&b)) return *this;
    this->judgeDelete();
    this->obj = b.obj;   //****** 两个类
    this->cnt = b.cnt;
    if (this->cnt != nullptr) {
      *(this->cnt)++;
    }
    return *this;
  }

  template<typename U> friend struct shared_ptr;


private:
  void initcnt()  { this->cnt = new int; }
  void setCnt(int x)   { *(this->cnt) = x; }
  void increase() { *(this->cnt)++; }
  void Decrease() { *(this->cnt)--; }
  bool isZero()   { return *(this->cnt) == 0; }
  void judgeDelete() {
    if (this->obj != nullptr) {
      this->Decrease();
      if (this->isZero()) {
        delete[] this->obj;
        delete this->cnt;
      }
    }
    this->obj = nullptr;
    this->cnt = nullptr;
  }
  T *obj;
  int *cnt;
};

struct A {
  virtual ~A() {
    cout << "d A" << endl;
  }
  virtual void say() { cout << "I am A" << endl; }
};

struct B : A {
  virtual ~B() {
    cout << "d B" << endl;
  }
  virtual void say() { cout << "I am B" << endl; }
};

int main() {
  shared_ptr<A> p;
  shared_ptr<B> q(new B());
  p = q;
  p->say();
  q->~B();
  p->~A();
  return 0;
}

