
# LinkedList

Author: Ali John

## Overview

The `LinkedList` class is a generic, singly linked list implementation in C++. It allows you to store elements of any type and provides a variety of utilities for managing the list.

## Features

- Generic (template-based): Works with any data type.
- Dynamic memory management.
- Core operations:  
  - Add and remove elements at both front and back.
  - Insert, erase, and set elements at any position.
  - Bulk insert and erase operations.
  - Convert to `std::vector`.
  - Access elements by index.
  - Clear the entire list.
  - Move semantics (move constructor and assignment).
  - Prevents accidental copying.

## Example Usage

```cpp
#include <iostream>
#include <vector>
#include "main.cpp" // or the file where LinkedList is defined

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
```

## Public Methods

- **Constructor**: Initialize from a `std::vector<T>`.
- **pushBack(T val)**: Add element to the end.
- **popBack()**: Remove element from the end.
- **pushFront(T val)**: Add element to the front.
- **popFront()**: Remove element from the front.
- **insertAt(size_t index, T val)**: Insert at index.
- **eraseAt(size_t index)**: Erase at index.
- **setAt(size_t index, T val)**: Set value at index.
- **insertVectorAt(size_t index, const std::vector<T>& data)**: Insert multiple elements at index.
- **eraseRange(size_t index, size_t count)**: Remove a range of elements.
- **toVector()**: Convert list to `std::vector<T>`.
- **size()**: Return the number of elements.
- **at(size_t index)**: Access element at index.
- **clear()**: Clear the list.
- **Move constructor and assignment**: Efficient list transfers.
- **Deleted copy constructor and assignment**: Prevents accidental copying.

## Exception Safety

- Throws `std::out_of_range` for invalid index access.

## License

This project is open-source and available under the MIT License.