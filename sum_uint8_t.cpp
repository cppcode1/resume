/*
copyright 2022 Oleksandr Chastukhin
*/
#include <iostream>
#include <cstdint>
#include <limits>
#include <any>
#include <type_traits>

using std::cout;
using std::endl;

template <typename type>
std::any sum(type a, type b)
{
    std::any result;

    // uint8_t + uint8_t = short
    if (std::is_same<uint8_t, type>::value)
    {
        cout << "the same" << endl;
        return std::any((short)(a + b));
    }

    return result;
}

int main()
{
    // compare uint8_t
    {
        // a max value of uint8_t is 255
        cout << (short)std::numeric_limits<uint8_t>::max() << endl;
        // if we sum 100 + 200 we will get the overflow
        uint8_t a = 100;
        uint8_t b = 200;
        uint8_t c = a + b;
        cout << (short)c << endl; // 44. the result is unexpected
        cout << (short)(a + b) << endl; // 300
        if (a + b == c) cout << "never be printed" << endl; // 300 == 44
        if (a + b == 300) cout << "a + b == 300" << endl;
        // how to sum uint8_t and don't get the overflow
        cout << std::any_cast<short>(sum(a, b)) << endl;
    }
    return 0;
}