#include <iostream>
#include <list>
#include <vector>

class Decimal {
 public:
  double value;
  Decimal(double v) : value(v) {}
};

template <typename N, typename D>
class Ratio {
 public:
  Ratio() : num_(), denom_() {}

  Ratio(const N& num, const D& denom)
      : num_(num), denom_(denom) {}

  operator double() const {
    return double(num_) /
           double(denom_);
  }

  operator Decimal() const {
    double temp =
        double(num_) / double(denom_);
    return Decimal(temp);
  }

 private:
  N num_;
  D denom_;
};

template <>
class Ratio<double, double> {
 public:
 private:
  double value_;
};

int main() {
  Ratio<int, double> b(4, 4.0);

  Decimal c = b;

  std::cout << c.value;
}

template <
    typename T,
    template <
        typename> typename InputContainer,
    template <
        typename> typename OutputContainer>

class DataTransformer {
 public:
  OutputContainer<T> transform(
      const InputContainer<T>& source) {
    OutputContainer<T> result;

    for (const auto& item : source) {
      T a = item * 2;
      result.push_back(a);
    }

    return result;
  }
};

int main() {
  std::list<int> starting_data = {
      1, 2, 3, 4};

  DataTransformer<
      int,
      std::list,
      std::vector>
      pipeline;

  std::vector<int> output =
      pipeline.transform(starting_data);

  for (int x : output) {
    std::cout << x << " ";
  }
}

template <
    typename T,
    template <
        typename...> typename Container>
class Builder {
  Container<T> data_;

 public:
  void add(const T& t) {
    data_.push_back(t);
  }
  void print() {
    for (const auto& x : data_)
      std::cout << x << " ";
    std::cout << std::endl;
  }
};

template <typename T>
class My_Vector {
 public:
  void push_back(const T& t) {}

  T* begin() { return arr_; }
  T* end() { return arr_ + size_; }

 private:
  T* arr_ = nullptr;
  size_t size_ = 0;
  size_t capacity_ = 0;
};

int main() {
  Builder<std::string, std::vector> c;

  c.add("ale");
  c.add("jorge");

  c.print();
}

consteval size_t length(const char* s) {
  size_t res = 0;
  while (*(s++)) ++res;
  return res;
}

int main(int argc, char const* argv[]) {
  std::cout << length("abc");

  char s[] = "runtime";
  std::cout << length(s);
}

template <typename T>
class ArrayOf2 {
 public:
  // este sirve para hacer
  // modificaciones
  T& operator[](size_t i) {
    std::cout << "reference"
              << std::endl;

    return a_[i];
  }

  const T& operator[](size_t i) const {
    std::cout << "constant"
              << std::endl;
    return a_[i];
  }

  T sum() const {
    return a_[0] + a_[1];
  }

 private:
  T a_[2];
};

template <typename T>
constexpr T pi = T(
    3.14159265358979323846264338327950288419716939937510582097494459230781L);

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

  // lazy instantiation of member
  // function sum() with type char*
  //  std::cout << c.sum() << std::endl;
}

#include <iomanip>
#include <iostream>

template <typename T>
constexpr T pi = T(
    3.14159265358979323846264338327950288419716939937510582097494459230781L);

int main() {
  std::cout << std::setprecision(20);
  std::cout << "Float: "
            << pi<float> << std::endl;
  std::cout << "Double: "
            << pi<double> << std::endl;
}

#include <iostream>

template <typename T, size_t N>
class Array {
 public:
  T& operator[](size_t i) {
    if (i >= N)
      throw std::out_of_range(
          "Bad Index");
    return data_[i];
  }

 private:
  T data_[N];
};

int main() {
  Array<int, 5> a;
  std::cin >> a[4];
  std::cout << a[4];

  Array<int, 2> b;
}