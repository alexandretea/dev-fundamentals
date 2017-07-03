// C/C++ File

// Author:   Alexandre Tea <alexandre.qtea@gmail.com>
// File:     /Users/alexandretea/Work/concepts/dynamic_programming/towersofhanoi.cpp
// Purpose:  TODO (a one-line explanation)
// Created:  2017-07-03 18:11:45
// Modified: 2017-07-03 18:35:30

#include <cstdlib>
#include <stack>
#include <stdexcept>
#include <iostream>

class HanoiTower : public std::stack<unsigned int>
{
    public:
        void
        push(unsigned int disk)
        {
            if (not empty() and top() < disk)
                throw std::runtime_error("Can't push bigger disk than last "
                                         "disk");
            std::stack<unsigned int>::push(disk);
        }
};

static void
push_from(HanoiTower& src, HanoiTower& dest)
{
    dest.push(src.top());
    src.pop();
}

void
move_disks(unsigned int nb_disks,
           HanoiTower& src, HanoiTower& dest, HanoiTower& buffer)
{
    if (nb_disks <= 0) {
        return ;
    }
    move_disks(nb_disks - 1, src, buffer, dest);
    push_from(src, dest);
    move_disks(nb_disks - 1, buffer, dest, src);
}

static void
debug_tower(HanoiTower tower)   // copy to avoid modifying tower
{
    while (not tower.empty()) {

        std::cout << tower.top() << " ";
        tower.pop();
    }
    std::cout << std::endl;
}

int
main()
{
    HanoiTower    tower_1;
    HanoiTower    tower_2;
    HanoiTower    tower_3;

    for (int i = 10; i >= 0; --i) {
        tower_1.push(i);
    }
    std::cout << "Before moving disks" << std::endl;
    std::cout << "Tower 1: "; debug_tower(tower_1);
    std::cout << "Tower 2: "; debug_tower(tower_2);
    std::cout << "Tower 3: "; debug_tower(tower_3);
    move_disks(tower_1.size(), tower_1, tower_3, tower_2);
    std::cout << "After moving disks" << std::endl;
    std::cout << "Tower 1: "; debug_tower(tower_1);
    std::cout << "Tower 2: "; debug_tower(tower_2);
    std::cout << "Tower 3: "; debug_tower(tower_3);
    return EXIT_SUCCESS;
}
