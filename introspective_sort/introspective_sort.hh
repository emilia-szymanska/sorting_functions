#ifndef INTROSPECTIVE_SORT
#define INTROSPECTIVE_SORT

#include <cmath> //for log2() function
#include "heap.hh"

template <typename T>
T * heapsort (T * tab, unsigned int index_left, unsigned int index_right);

template <typename T>
int quicksort_partition (T *tab, unsigned int index_left, unsigned int index_right);


template <typename T>
T * insertion_sort (T *tab, unsigned int index_left, unsigned int index_right);

template <typename T>
T * sorting_function (T *tab, unsigned int index_left, unsigned int index_right, int recursion);

template <typename T>
void introsort (T *tab, unsigned int length);

#include "introspective_sort.cpp"


#endif
