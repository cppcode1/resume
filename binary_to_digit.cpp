/*
copyright 2021 Oleksandr Chastukhin
the task is to write functions to convert a binary value to its digit equivalent and vise versa.
bit = 2^bit number - 1
 */
#include <stdio.h>
#include <math.h>
#include <string>

using std::string;

int binary_to_digit(const string& binary)
{
    int result = 0;
    const short bits_count = binary.size();
    short power = binary.size() - 1;
    for (int i = 0; i < bits_count; ++i)
    {
        if (binary[i] == '1')
            result += (int)pow(2, power);
        //printf("%d\n", (int)pow(2, power));
        power--;
    }
    return result;
}

string digit_to_binary(int digit)
{
    string result = "";
    const short bit_count = (sizeof(digit) * 8) - 1;
    // 1) if the digit >= 2^bit number - 1 then set a bit to 1
    // 2) then digit = 2^bit number - 1 
    // 3) continue
    for (int i = bit_count; i != 0; --i) // go from 31 to 1 through all bits
    {
        const unsigned power = static_cast<int>(pow(2, i));
        //printf("%u\n", power);
        if (digit >= power)
        {
            result = result + "1";
            digit = digit - power;
        }
        else
        {
            result = result + "0";
        }
    }
    return result;
}

int main()
{
    printf("11111111 is %d\n", binary_to_digit("11111111")); // 255 = octat of IP address
    printf("128 is %s", digit_to_binary(128).c_str()); // 0000000000000000000000001000000
    return 0;
}