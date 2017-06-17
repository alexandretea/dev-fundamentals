// C/C++ File

// Author:	 Alexandre Tea <alexandre.qtea@gmail.com>
// File:	 /Users/alexandretea/Work/concepts/search/radio_transmitters.cpp
// Purpose:  TODO (a one-line explanation)
// Created:  2017-06-16 13:59:10
// Modified: 2017-06-16 17:15:30

#include <algorithm>
#include <vector>
#include <iostream>

int
find_farthest_house(std::vector<bool> const& map,
                    unsigned int pos, unsigned int range)
{
    unsigned int i = pos + range;

    if (pos == map.size() - 1)
        return -1;
    else if (i >= map.size())
        i = map.size() - 1;
    for (; i > pos; --i) {
        if (map[i])
            return i;
    }
    return -1;
}

size_t
find_required_transmitters(std::vector<int> const& houses, unsigned int range)
{
    unsigned int        nb_transmitters = 0;
    std::vector<bool>   map(houses.back(), false);

    for (auto& house: houses)
        map[house - 1] = true;
    for (unsigned int location = 0; location < map.size(); ++location) {
        if (map[location]) {
            int farthest = find_farthest_house(map, location, range);

            if (farthest != -1)
                location = farthest + range;
            else
                location += range;
            ++nb_transmitters;
        }
    }
    return nb_transmitters;
}

int
main()
{
	int n;
	int k;
	std::cin >> n >> k;

	std::vector<int> x(n);

	for (int x_i = 0; x_i < n; ++x_i) {
        std::cin >> x[x_i];
	}
    std::sort(x.begin(), x.end());
    std::cout << find_required_transmitters(x, k) << std::endl;
	return 0;
}
