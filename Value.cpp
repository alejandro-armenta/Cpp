template <typename T>
auto sum(T first)
{
    return first;
}

template <typename T, typename... Args>
auto sum(T first, Args... args)
{
    return first + sum(args...);
}

template <typename T>
class Value;

template <typename T>
class Value<T*>
{
public:
    explicit Value(T* p) : v_(*p) {}

private:
    T v_;
};

template <typename T>
class Value<T&>
{
public:
    explicit Value(T& p) : v_(p) {}

private:
    T v_;
};

int main()
{
    double a = 2;
    Value<double*> ale(&a);
    Value<double&> ale_(a);
}