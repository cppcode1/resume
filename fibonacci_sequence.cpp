/*

copyright 2021 Oleksandr Chastukhin

the goal is to implement a function to compute number from Fibonacci sequence.
*/

#include <iostream>
using namespace std;

/**
 * it computes 'count' first Fibonacci numbers starting from prev1 and prev2
 */
int get_fibonacci_number(const int count, const int previous1 = 0, const int previous2 = 1)
{
    // 1: 0 + 1 = 1
    // 2: 1 + 1 = 2
    // 3: 2 + 1 = 3
    // 4: 3 + 2 = 5

    const int number = previous1 + previous2;
    cout << count << ": " << number << endl;

    if (count == 1)
        return number;

    // compute the next number in the sequence
    return get_fibonacci_number(count - 1, previous2, number);
}

int main()
{
    // get first 10 number starting from 0 and 1
    get_fibonacci_number(10, 0, 1);
    return 0;
}
