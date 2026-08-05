#include <iostream>

class Base {
 public:
  virtual void f() { std::cout << "Base" << std::endl; }
  void g() { f(); }
};

class Derived : private Base {
 public:
  void f() override { std::cout << "Derived" << std::endl; }

  void h() { g(); }
};

int main() {
  Derived d;

  d.h();
}