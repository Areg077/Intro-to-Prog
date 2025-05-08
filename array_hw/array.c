#include "array.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// Create a new dynamic array
struct array* array_create()
{
    struct array* a = (struct array*)malloc(sizeof(struct array)); // allocate memory for the array struct
    assert(0 != a); // make sure memory allocation worked
    memset(a, 0, sizeof(struct array)); // clear all fields to zero
    a->size = 0; // no elements yet
    a->capacity = 2; // initial capacity is 2
    a->start = (element_type*)malloc(a->capacity * sizeof(element_type)); // allocate space for 2 elements
    return a;
}

// Add an element to the end of the array
void array_push_back(struct array* a, element_type e)
{
    assert(a != 0); // check array is not NULL

    if (a->size >= a->capacity) {
        a->capacity *= 2; // double the capacity
        a->start = realloc(a->start, a->capacity * sizeof(element_type)); // resize the memory block
    }

    a->start[a->size] = e; // place the element at the end
    a->size++; // increase the size
}

// Remove the last element from the array
void array_pop_back(struct array* a)
{
    assert(a != 0); // check array is not NULL
    assert(a->size > 0); // make sure there is something to remove

    a->size--; // just decrease size to "ignore" the last element
}

// Insert an element at a specific index
void array_insert(struct array* a, size_type index, element_type e)
{
    assert(a != 0); // check array is not NULL
    assert(index <= a->size); // index must be in valid range (can insert at the end)

    if (a->size >= a->capacity) {
        a->capacity *= 2; // double the capacity if full
        a->start = realloc(a->start, a->capacity * sizeof(element_type)); // resize memory
    }

    // Shift elements to the right to make room for new element
    for (size_type i = a->size; i > index; i--) {
        a->start[i] = a->start[i - 1];
    }

    a->start[index] = e; // insert new element
    a->size++; // update size
}

// Return the number of elements in the array
size_type array_size(struct array* a)
{
    assert(0 != a);
    return a->size;
}

// Return how many elements the array can hold before resizing
size_type array_capacity(struct array* a)
{
    assert(0 != a);
    return a->capacity;
}

// Print the contents of the array
void array_print(struct array* a)
{
    assert(0 != a);
    for (size_type i = 0; i < a->size; ++i) {
        printf("%d ", a->start[i]); // print each element
    }
    printf("\nsize = %d", a->size); // print size
    printf("\ncapacity = %d\n\n", a->capacity); // print capacity
}

// Check if the array is empty
int array_empty(struct array* a)
{
    assert(0 != a);
    return a->size == 0; // returns 1 if empty, 0 otherwise
}
