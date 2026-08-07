#include <iostream>

class Decimal
{
public:
    double value;
    Decimal(double v) : value(v) {}
};

template <typename N, typename D>
class Ratio
{
public:
    Ratio() : num_(), denom_() {}

    Ratio(const N& num, const D& denom) : num_(num), denom_(denom)
    {
    }

    operator double() const
    {
        return double(num_) / double(denom_);
    }

private:
    N num_;
    D denom_;
};

template <typename N, typename D>
class Ratio<N*, D*>
{
public:
    Ratio(N* num, D* denom) : num_(num), denom_(denom)
    {
        if (!num || !denom)
        {
            throw std::invalid_argument(
                "Ratio pointers cannot be nullptr");
        }
    }

    operator double() const
    {
        return double(*num_) / double(*denom_);
    }

private:
    N* const num_;
    D* const denom_;
};

template <typename D>
class Ratio<double, D>
{
public:
    Ratio() : value_() {}

    Ratio(const double& num, const D& denom)
        : value_(num / double(denom))
    {
    }

    operator double() const { return value_; }

private:
    double value_;
};

template <typename N>
class Ratio<N, double>
{
public:
    Ratio() : value_() {}

    Ratio(const N& num, const double& denom)
        : value_(double(num) / denom)
    {
    }

    operator double() const { return value_; }

private:
    double value_;
};

template <>
class Ratio<double, double>
{
public:
    Ratio() : value_() {}

    template <typename A, typename B>
    Ratio(const Ratio<A, B>& a) : value_(double(a))
    {
    }

    template <typename N, typename D>
    Ratio(const N& num, const D& denom)
        : value_(double(num) / double(denom))
    {
    }

    operator double() const { return value_; }

private:
    double value_;
};

template <>
Ratio<float, float>::operator double() const
{
    return num_ / denom_;
}

int main()
{
    int a = 5;
    double b = 10.0;

    Ratio<int*, double*> c(nullptr, &b);

    std::cout << double(c);
}