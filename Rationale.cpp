/*

    bird es el mas general

flying bird     flyless bird

eagle           penguin

public is an instance

private has an instance

some method is part of the public interface

*/

#include <iostream>

// cuando son miembros tienen que ser el izquierdo

class Rational {
 public:
  Rational(long a, long b) {
    n_ = a;
    d_ = b;
  }
  Rational& operator+=(const Rational& rhs);

  std::ostream& operator<<(std::ostream& os);

 private:
  long n_;
  long d_;
};

Rational& Rational::operator+=(const Rational& rhs) {
  n_ = n_ * rhs.d_ + d_ * rhs.n_;
  d_ = d_ * rhs.d_;
  return *this;
}

std::ostream& Rational::operator<<(std::ostream& os) {
  os << n_ << "/" << d_;
  return os;
}

int main() {
  Rational a(1, 2), b(1, 2);
  a += b;
  a << std::cout << "\n";
}
