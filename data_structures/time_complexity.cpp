/** copyright 2021 Oleksandr Chastukhin 
 * 
*/
#include <iostream>

using namespace std;

int main()
{
    const char letter[] = {'a', 'b', 'c'};
    const int number[] = {1, 2, 3};

    const int array_size = sizeof(letter) / sizeof(letter[0]);
    cout << "array size = " << array_size << endl;

    // combine every letter with every number
    string pair;
    for (int i = 0; i < array_size; ++i) // x^1 = linear - time complexity = 3
    {
        for (int j = 0; j < array_size; ++j) // x^2 - time complexity = 3*3=9
        {
            pair.clear();
            pair = letter[i]; // convert char to string
            pair += to_string(number[j]); // convert int to string
            cout << pair << endl;
        }
    }
    return 0;
}