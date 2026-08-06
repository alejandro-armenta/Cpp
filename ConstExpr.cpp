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

// especialization
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

int main() {
  Ratio<int, int> b(4, 4.0);

  Ratio<double, double> c = b;

  std::cout << double(c);
}