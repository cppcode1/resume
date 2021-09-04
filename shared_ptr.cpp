/*
copyright 2021 Oleksandr Chastukhin

the shared smart pointer example
the goal is to exercise std::shared_ptr.

attributes of smart pointers:
- atomatic momory deallocation
- safe access in case of multi threading (atomic)
- unsafe reading in case of multi threading. the mutex must be applied
*/

#include <memory>
#include <iostream>

using namespace std;

struct info
{
    int size;
};

int main()
{
    // create the object of shared pointer
    shared_ptr<info> pointer;
    const bool is_empty1 = static_cast<bool>(pointer) == false; // C++ style
    const bool is_empty2 = (bool)pointer == false; // C style
    const bool is_empty3 = pointer.operator bool() == false; // use 'operator bool'

    // check if it is empty, thanks to operator bool conversion
    if (is_empty1)
    {
        cout << "the pointer is empty and it must be initialized first" << endl;
        // initialize it with a new dinimically allocated value
        pointer = shared_ptr<info>(new info);
    }

    // access to the value using -> (arrow) sign
    pointer->size = 8;
    cout << pointer->size << endl;

    return 0;
}