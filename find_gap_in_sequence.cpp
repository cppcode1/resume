/*
copyright 2021 Oleksandr Chastukhin

the goal is to find a missing element inside a sorted sequence of positive numbers from 1 to 10 and the next element is greater than the previous one by 1.

the first solution uses simple for loop to check every pair of elements and if there is a gap between them, we will return this value.

the second solution uses the recursive method and the binary search for the sorted sequence. given that the sequence is sorted we can easily determine in which part of sequence the gap exists. then I traverse the array by 2 parts and select only part where the gap is and then do it again in the next iteration until there will be 2 elements in the array. between them there is a gap.

the outcome
iteration:1 start_index:0 end_index:8 range_size:9 center_index:4 go to: right
iteration:2 start_index:4 end_index:8 range_size:5 center_index:6 go to: right
iteration:3 start_index:6 end_index:8 range_size:3 center_index:7 go to: right
iteration:4 start_index:7 end_index:8 range_size:2 center_index:7 go to: right
the missing element is 9

 */
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
using std::string;

int find_missing_element_v1(const vector<int>& sequence)
{
    for (int i = 0; i < sequence.size() -1; ++i)
        if (sequence[i+1] - sequence[i] > 1)
            return sequence[i] + 1;
    return -1;
}

int find_missing_element_v2(const vector<int>& sequence, int start, int end)
{
    // the gap exists if the last element doesn't equal to the count of elements
    const bool gap_exists = sequence.back() != sequence.size();
    if (!gap_exists)
    {
        cout << "the gap doesn't exist" << endl;
        return -1;
    }

    static int iteration = 0;
    iteration++;

    const int range = end - start;
    const int range_center = (range / 2) + start;
    const bool gap_on_the_left = sequence[range_center] != range_center + 1;
    const bool gap_on_the_right = gap_on_the_left == false;
    const string direction = gap_on_the_left ? "left" : "right";

    cout << "iteration:" << iteration
    << " start_index:" << start
    << " end_index:" << end
    << " range_size:" << range + 1
    << " center_index:" << range_center
    << " go to: " << direction
    << endl;

    // stop if there are only 2 elements between which the gap exists
    if (end - start == 1)
    {
        cout << "the missing element is " << sequence[start] + 1 << endl;
        return sequence[start] + 1;
    }
    // otherwise go left or right
    else if (gap_on_the_left)
        return find_missing_element_v2(sequence, start, range_center);
    return find_missing_element_v2(sequence, range_center, end);
}

int main()
{
    //                      0  1  2  3  4  5  6  7  8
    vector<int> sequence = {1, 2, 3, 4, 5, 6, 7, 8, 10}; // 9 is missing
    find_missing_element_v2(sequence, 0, sequence.size() - 1);
    return 0;
}