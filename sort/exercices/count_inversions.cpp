// C/C++ File

// Author:   Alexandre Tea <alexandre.qtea@gmail.com>
// File:     /Users/alexandretea/Work/concepts/sort/exercices/count_inversions.cpp
// Purpose:  TODO (a one-line explanation)
// Created:  2017-06-14 16:59:41
// Modified: 2017-06-14 19:03:11

#include <iostream>
#include <vector>

static long long
merge_halves(std::vector<int>& array, std::vector<int>& helper,
             unsigned int f_start, unsigned int f_end,
             unsigned int s_start, unsigned int s_end)
{
    long long           nb_inversions = 0;
    unsigned int        s_i = s_start;

    //std::cout << "halves: " << f_start << "-" << f_end << ";" << s_start << "-" << s_end << std::endl;
    for (unsigned int f_i = f_start; f_i <= f_end;) {
        if (s_i > s_end or array[f_i] <= array[s_i]) {
            helper.push_back(array[f_i]);
            ++f_i;
        } else {
            helper.push_back(array[s_i]);
            //std::cout << "nb_inversions moving " << s_i << ": "
                //<< s_start << " - " << f_i
                //<< " = "
                //<< (s_start - f_i) << std::endl;
            nb_inversions += s_start - f_i;
            ++s_i;
        }
    }
    for (; s_i <= s_end; ++s_i) {
        helper.push_back(array[s_i]);
    }

    // update original array
    s_i = f_start;
    for (auto& v: helper) {
        array[s_i] = v;
        ++s_i;
    }
    helper.clear();
    return nb_inversions;
}


static long long
mergesort(std::vector<int>& array, unsigned int start, unsigned int end,
          std::vector<int>& helper)
{
    unsigned int array_size = end - start + 1;
    unsigned int split_i = start + (array_size / 2);
    long long    nb_inversions = 0;

    if (array_size > 1) {
        // first half indexes
        unsigned int first_start = start;
        unsigned int first_end = split_i - 1;
        // second half indexes
        unsigned int sec_start = split_i;
        unsigned int sec_end = end;

        nb_inversions += mergesort(array, first_start, first_end, helper);
        nb_inversions += mergesort(array, sec_start, sec_end, helper);
        nb_inversions += merge_halves(array, helper,
                                      first_start, first_end,
                                      sec_start, sec_end);
    }
    return nb_inversions;
}

static long long
count_inversions(std::vector<int> array)
{
    std::vector<int>    helper;

    helper.reserve(array.size());
    return mergesort(array, 0, array.size() - 1, helper);
}

int
main() {
    int t;
    std::cin >> t;

    for(int a0 = 0; a0 < t; a0++) {
        int n;
        std::cin >> n;

        std::vector<int> arr(n);

        for(int arr_i = 0; arr_i < n; ++arr_i) {
            std::cin >> arr[arr_i];
        }
        std::cout << count_inversions(arr) << std::endl;
    }
    return 0;
}
