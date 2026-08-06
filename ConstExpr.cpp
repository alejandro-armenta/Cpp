#include <iostream>

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
    return double(num_) / double(denom_);
  }

 private:
  N num_;
  D denom_;
};

template <typename D>
class Ratio<double, D> {
 public:
  Ratio() : value_() {}

  Ratio(const double& num, const D& denom)
      : value_(num / double(denom)) {}

  operator double() const { return value_; }

 private:
  double value_;
};

template <typename N>
class Ratio<N, double> {
 public:
  Ratio() : value_() {}

  Ratio(const N& num, const double& denom)
      : value_(double(num) / denom) {}

  operator double() const { return value_; }

 private:
  double value_;
};

template <>
class Ratio<double, double> {
 public:
  Ratio() : value_() {}

  template <typename A, typename B>
  Ratio(const Ratio<A, B>& a) : value_(double(a)) {}

  template <typename N, typename D>
  Ratio(const N& num, const D& denom)
      : value_(double(num) / double(denom)) {}

  operator double() const { return value_; }

 private:
  double value_;
};

template <>
Ratio<float, float>::operator double() const {
  return num_ / denom_;
}

int main() {
  Ratio<double, float> b(4, 4.0);

  Ratio<float, double> c(2, 2.0);

  std::cout << double(c);
}