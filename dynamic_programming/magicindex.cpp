// C/C++ File

// Author:   Alexandre Tea <alexandre.qtea@gmail.com>
// File:     /Users/alexandretea/Work/concepts/dynamic_programming/magicindex.cpp
// Purpose:  TODO (a one-line explanation)
// Created:  2017-07-03 14:02:51
// Modified: 2017-07-03 14:26:44

#include <iostream>
#include <cstdlib>
#include <iterator>
#include <vector>

// magic index means index which value is equal to index
// arrays are sorted and might contain distinct values or not

static int
rec_magicindex_distinct(std::vector<int> const& arr,
                         size_t begin, size_t end)
{
    size_t  size = end - begin;
    size_t  pivot;

    if (size == 1)
        return (arr[begin] == begin ? begin : -1);
    pivot = begin + size / 2;
    if (arr[pivot] == pivot)
        return pivot;
    else if (arr[pivot] > pivot)
        return rec_magicindex_distinct(arr, begin, pivot);
    return rec_magicindex_distinct(arr, pivot, end);
}

// O(log n)
// Binary search
static int
magicindex_distinct(std::vector<int> const& arr)
{
    return rec_magicindex_distinct(arr, 0, arr.size());
}

// O(log n)
static int
magicindex_non_distinct(std::vector<int> const& arr)
{
    unsigned int i = 0;

    while (i < arr.size()) {

        if (arr[i] == i)
            return i;
        else if (arr[i] > i)
            i = arr[i];
        else
            ++i;
    }
    return -1;
}

int main()
{
    std::vector<int>    test_distinct = {
        -1, 0, 1, 2, 3, 5, 7
    };
    std::vector<int>    test_non_distinct = {
        1, 2, 4, 4, 5, 5, 5, 5
    };
    std::vector<int>    test_fail = {
        1, 2, 3, 4, 5, 6, 7
    };

    std::cout << magicindex_distinct(test_distinct) << std::endl;
    std::cout << magicindex_non_distinct(test_non_distinct) << std::endl;
    std::cout << magicindex_distinct(test_fail) << std::endl;
    std::cout << magicindex_non_distinct(test_fail) << std::endl;
    return EXIT_SUCCESS;
}
