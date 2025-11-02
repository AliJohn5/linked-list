#include "linked_list.hpp"


int main()
{

    LinkedList<int> data(std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9});

    for (const auto &x : data.toVector())
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "Size: " << data.size() << std::endl;

    data.pushBack(10);

    std::cout << "Element at index 5: " << data.at(5) << std::endl;

    std::cout << "New Size: " << data.size() << std::endl;

    data.clear();

    std::cout << "Size after clear: " << data.size() << std::endl;

    return 0;
}