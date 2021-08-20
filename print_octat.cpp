/*
copyright 2021 Oleksandr Chastukhin
IP address octat
this small example shows how to convert the binary IP octat to the whole number and vise versa.

https://en.cppreference.com/w/cpp/utility/bitset
 */
#include <iostream>
#include <math.h>
#include <bitset>
#include <string>

using namespace std;

// convert the binary to its whole/decimal number equivalent
unsigned long binary_to_digit(const string& binary)
{
    bitset<8> bits{binary};
    return bits.to_ulong();
}

// convert a decimal number to its binary equivalent
string digit_to_binary(unsigned short octat)
{
    return "";
}

int main()
{
    // 0b10000000                              - C++ binary liteeral
    // 8    7    6    5    4   3     2    1    - bit number (one IP octat = 8 bits)
    // 128  64   32   16   8   4     2    1    - decinal number
    // 2^7  2^6  2^5  2^4  2^3 2^2   2^1  2^0  - suitable power

    unsigned short octat1 = 0b10000000; // 128, binary literal
    unsigned short octat2 = static_cast<int>(pow(2,7)); // 128 = 2^7
    auto octat3 = binary_to_digit("10000000"); // 128

    cout << octat1 << " = " << octat2 << " = " << octat3 << endl;

    return 0;
}

/*
the outcome
fire up the app
128 = 128 = 128
done
 */