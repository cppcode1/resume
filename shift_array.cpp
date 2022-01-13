// copyright 2022 Oleksandr Chastukhin
// the goal this to move the wrong elements -1 to the right and keep the order of good elements

#include <iostream>
#include <vector>
using namespace std;

void print(const std::vector<int>& values, const std::size_t start = 0)
{
    for (auto idx = start; idx < values.size(); ++idx)
        std::cout << values[idx] << " ";
    std::cout << std::endl;
}

void shift_to_right(std::vector<int>& values, const int start, const int end, const int filler = -1)
{
    //cout << "last element index is " << values.size() - 1 << endl;
    // before   1  2 3 4 5
    // after    -1 1 2 3 4
    int next = 0;
    // go from the end to the start
    for (int i = end; i > start; i--)
    {
        next = values[i-1];
        // the next element must equal to the previous one
        values[i-1] = values[i];
        // and the current is the next
        values[i] = next;
        //print(values, 0);
    }
    // we moved all elements ahead by 1 and now there is a gap at the beginning
    values[start] = filler;
}

std::size_t MoveInvalidValuesToLeft(std::vector<int>& values, const int invalid_value)
{
    unsigned last_invalid_index = 0;
    for (int i = 0; i < values.size(); i++)
    {
        // the solution with keeping the order
        if (values[i] == invalid_value)
        {
            shift_to_right(values, last_invalid_index, i, invalid_value);
            last_invalid_index++;
        }
        // the solution without keeping the order
        /*if (values[i] == invalid_value)
        {
            std::swap(values[i], values[last_invalid_index]);
            last_invalid_index++;
        }*/
    }
    return 0;
}


int main()
{
    const int invalid_value = -1;
    std::vector<int> values{10,-1,20,30,-1,40,-1,50,60,70};
    print(values);

    MoveInvalidValuesToLeft(values, -1);
    cout << endl;
    print(values);

    /*std::vector<int> test2{-1,56,45,-1,8,27,-1,91,38,11,-1};
    print(test2);
    start = MoveInvalidValuesToLeft(test2, invalid_value);
    print(test2, start);*/
}



