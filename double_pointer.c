/*
copyright 2021 Oleksandr Chastukhin
subject:
a double pointer in C language

what does it for?
we need a pointer to a pointer to pass the pointer by reference like C++ can do with int*&. the goal is to modify the original pointer address.

description:
this example shows how to use a double pointer to pass a pointer to a function. a double pointer stores the address of another pointer.

how to compile: 
$ gcc double_pointer.c -o app && ./app && rm app

the outcome:
the data address before change = 0x7ffd099e73f4
data is 3 or 3 or 2
data address is 0x55fcb3c096b0 or 0x55fcb3c096b0 or 0x7ffd099e73f4
data pointer address is 0x7ffd099e73f8 or 0x7ffd099e73f8 or 0x7ffd099e73f8
data double pointer address is 0x7ffd099e7400

 */

#include <stdio.h>
#include <stdlib.h> // malloc

// it can change the original pointer address
// int** is the same as int*& in C++
void change(int** double_pointer)
{
    *double_pointer = malloc(sizeof(int)); // access int*
    **double_pointer = 3; // access int
}

int main()
{
    int data = 1;
    int* pointer = &data;
    *pointer = 2;
    int** double_pointer = &pointer;
    printf("the data address before change = %p\n", pointer);
    change(double_pointer);

    printf("data is %d or %d or %d\n", **double_pointer, *pointer, data);
    printf("data address is %p or %p or %p\n", &**double_pointer, pointer, &data);
    printf("data pointer address is %p or %p or %p\n", double_pointer, &*double_pointer, &pointer);
    printf("data double pointer address is %p\n", &double_pointer);

    //printf("the size of a double pointer is %ld\n", ); // 8

    return 0;
}