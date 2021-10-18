/*
copyright 2021 Oleksandr Chastukhin
the goal is to get the current byte order (endian) of the operating system. to detect the endian I use the bit operations. first I ebable the first bit and next move it to get 0. the endian is detected of the 0 value is achieved.

use 'lscpu' command to get the byte order on Linux

 */
#include <iostream>
using namespace std;

int main()
{
    // set the first bit. it can be the first bit from the left or the right depending on the endian
    int i = 0b1;

    // little endian: bits goes from the left to the right as follows:
    // 8    7    6    5    4   3     2    1    - bit number (one IP octat = 8 bits)
    // 128  64   32   16   8   4     2    1    - decinal number
    // 2^7  2^6  2^5  2^4  2^3 2^2   2^1  2^0  - suitable power
    // so get 0 we need to move 1 bit to the right:
    const bool is_little_endian = (i >> 1) == 0;

    // big endian: bits goes from the left to the right, so to get 0 we need to move our bit to the left:
    const bool is_big_endian = (i << 1) == 0;

    if (is_little_endian)
        cout << "it is the little endian" << endl;

    if (is_big_endian)
         cout << "it is the big endian" << endl;

    return 0;
}