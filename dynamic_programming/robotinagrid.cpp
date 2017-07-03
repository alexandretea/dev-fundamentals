// C/C++ File

// Author:   Alexandre Tea <alexandre.qtea@gmail.com>
// File:     /Users/alexandretea/Work/concepts/dynamic_programming/robotinagrid.cpp
// Purpose:  TODO (a one-line explanation)
// Created:  2017-07-03 15:00:16
// Modified: 2017-07-03 16:04:09

#include <vector>
#include <cstdlib>
#include <utility>
#include <iostream>

// robot can only move to the right or to the bottom
// starts at 0,0 and needs to find a path to the bottom-right corner

struct Coordinates
{
    ssize_t x;
    ssize_t y;

    bool
    operator==(Coordinates const& other) const {
        return x == other.x and y == other.y;
    }
};

static bool
rec_robot_in_a_grid(std::vector<std::vector<bool>>& grid,
                    Coordinates const& target,
                    std::vector<Coordinates>& path)
{
    Coordinates dest;

    path.push_back(target);
    //std::cout   << "debug: ("
                //<< target.x << "," << target.y
                //<< ")" << std::endl;

    if (target.x == 0 and target.y == 0)
        return true;

    // left cell
    dest = { target.x - 1, target.y };
    if (dest.x >= 0
        and not grid[dest.y][dest.x]
        and std::find(path.begin(), path.end(), dest) == path.end()
        and rec_robot_in_a_grid(grid, dest, path)) {
        return true;
    }

    // up cell
    dest = { target.x, target.y - 1 };
    if (dest.y >= 0
        and not grid[dest.y][dest.x]
        and std::find(path.begin(), path.end(), dest) == path.end()
        and rec_robot_in_a_grid(grid, dest, path)) {
        return true;
    }

    // memoisation
    grid[target.y][target.x] = true;
    path.pop_back();
    return false;
}

// takes a copy of grid bc algorithm might edit it to indicate that no path
// was found through specific coordinates
static std::vector<Coordinates>
robot_in_a_grid(std::vector<std::vector<bool>> grid)
{
    std::vector<Coordinates>    path;

    rec_robot_in_a_grid(grid,
            Coordinates { static_cast<ssize_t>(grid[0].size()) - 1,
                          static_cast<ssize_t>(grid.size()) - 1 },
            path);
    std::reverse(path.begin(), path.end());
    return path;
}

static void
test_and_print(std::vector<std::vector<bool>> const& grid)
{
    std::vector<Coordinates>        path;

    path = robot_in_a_grid(grid);
    if (path.empty()) {
        std::cout << "no path found" << std::endl;
        return ;
    }
    for (auto& coo: path) {
        std::cout << "(" << coo.x << "," << coo.y << ") ";
    }
    std::cout << std::endl;
}

int
main()
{
    std::vector<std::vector<bool>>  easy {
        { 0, 0, 1 },
        { 1, 0, 1 },
        { 0, 0, 0 },
    };
    std::vector<std::vector<bool>>  empty {
        { 0, 0, 0 },
        { 0, 0, 0 },
        { 0, 0, 0 },
    };
    std::vector<std::vector<bool>>  fail {
        { 0, 0, 0 },
        { 0, 1, 1 },
        { 0, 1, 0 },
    };
    std::vector<std::vector<bool>>  hard {
    //    0  1  2  3  4  5  6  7
        { 0, 0, 0, 0, 1, 0, 0, 0 }, // 0
        { 1, 1, 0, 1, 0, 1, 0, 0 }, // 1
        { 0, 0, 0, 1, 0, 0, 1, 0 }, // 2
        { 0, 0, 0, 0, 0, 0, 0, 0 }, // 3
        { 0, 1, 0, 0, 0, 1, 0, 0 }, // 4
        { 0, 0, 0, 1, 0, 0, 1, 0 }, // 5
        { 0, 1, 0, 0, 0, 1, 1, 0 }, // 6
        { 0, 0, 1, 1, 0, 1, 0, 0 }, // 7
    };

    test_and_print(easy);
    test_and_print(empty);
    test_and_print(fail);
    test_and_print(hard);
    return EXIT_SUCCESS;
}
