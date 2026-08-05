#include <iostream>

template <typename T>
class ArrayOf2 {
 public:
  // este sirve para hacer modificaciones
  T& operator[](size_t i) {
    std::cout << "reference" << std::endl;

    return a_[i];
  }

  const T& operator[](size_t i) const {
    std::cout << "constant" << std::endl;
    return a_[i];
  }

  T sum() const { return a_[0] + a_[1]; }

 private:
  T a_[2];
};

template <typename T>
constexpr T pi =
    T(3.14159265358979323846264338327950288419716939937510582097494459230781L);

int main() {
  std::cout << pi<float> << std::endl;
  std::cout << pi<double> << std::endl;

  ArrayOf2<int> i;

  i[0] = 2;
  i[1] = 2;

  std::cout << i.sum() << std::endl;

  ArrayOf2<double> x;

  x[0] = -3.5;
  x[1] = 4.0;

  std::cout << x.sum() << std::endl;

  ArrayOf2<char*> c;

  char s[] = "Hello";

  c[0] = s;
  c[1] = s + 2;

  // lazy instantiation of member function sum() with type char*
  //  std::cout << c.sum() << std::endl;
}

#include <iomanip>
#include <iostream>

template <typename T>
constexpr T pi =
    T(3.14159265358979323846264338327950288419716939937510582097494459230781L);

int main() {
  std::cout << std::setprecision(20);
  std::cout << "Float: " << pi<float> << std::endl;
  std::cout << "Double: " << pi<double> << std::endl;
}
