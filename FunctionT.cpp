#include <iostream>

template <typename... T>
struct Group;

template <typename T>
struct Group<T>
{
    T t_;

    Group() = default;

    explicit Group(const T& t) : t_(t) {}

    explicit Group(T&& t) : t_(std::move(t)) {}

    explicit operator const T&() const { return t_; };
};

int main()
{
    Group<int> g(3);

    int i = static_cast<int>(g) + 10;

    std::cout << i;
}
