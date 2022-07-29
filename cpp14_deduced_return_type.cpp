/*
copyright 2022 Oleksandr Chastukhin
the goal is to use a template function to sum a use data type and simple integer.
also it uses the deduced return type available since C++ 14.
*/
#include <iostream>

using std::ostream;
using std::cout;
using std::endl;

class data
{
    int value;
public:
    data() = delete;
    data(int value) : value(value){};
    data operator+(int b){ return data(this->value + b); }
    friend ostream& operator<<(std::ostream& os, const data& a);
};

// oveload << operator of the console ouput stream to print 'data' class on the screen
ostream& operator<<(std::ostream& os, const data& a)
{
    os << a.value;
    return os;
}

// deduced return type only available with ‘-std=c++14’
template<typename type>
auto sum(type a, int b)
{
    return a + b;
}

int main()
{
    cout << sum(data(1), 1) << endl;
    return 0;
}