#include <iostream>
#include <vector>

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T content;
        Node *child = nullptr;
        Node(T val) : content(val) {}
    };

    Node *_root = nullptr;
    Node *_last = nullptr;
    size_t _size = 0;

public:
    LinkedList(std::vector<T> data)
    {
        if (!data.empty())
        {
            _root = new Node(data[0]);
            ++_size;
        }
        {
            _root = new Node(data[0]);
        }

        Node *n = _root;

        for (int i = 1; i < data.size(); ++i)
        {
            Node *newNode = new Node(data[i]);
            n->child = newNode;
            n = newNode;
            _last = n;
        }

        _size = data.size();
    }

    ~LinkedList()
    {
        Node *n = _root;

        while (n != nullptr)
        {
            n = _root->child;
            delete _root;
            _root = n;
        }
    }

    std::vector<T> toVector()
    {
        Node *n = _root;
        std::vector<T> ans(_size);

        for (size_t i = 0; i < _size; ++i)
        {
            ans[i] = n->content;
            n = n->child;
        }

        return ans;
    }

    void pushBack(T val)
    {
        Node *newNode = new Node(val);

        if (_last != nullptr)
        {
            _last->child = newNode;
            _last = newNode;
        }
        else
        {
            _root = newNode;
            _last = newNode;
        }

        ++_size;
    }

    void popBack()
    {
        if (_size == 0)
        {
            return;
        }

        if (_size == 1)
        {
            delete _root;
            _root = nullptr;
            _last = nullptr;
            _size = 0;
            return;
        }

        Node *n = _root;

        while (n->child != _last)
        {
            n = n->child;
        }

        delete _last;
        n->child = nullptr;
        _last = n;
        --_size;
    }

    void pushFront(T val)
    {
        Node *newNode = new Node(val);

        if (_root != nullptr)
        {
            newNode->child = _root;
            _root = newNode;
        }
        else
        {
            _root = newNode;
            _last = newNode;
        }

        ++_size;
    }

    void popFront()
    {
        if (_size == 0)
        {
            return;
        }

        Node *n = _root;
        _root = _root->child;
        delete n;
        --_size;

        if (_size == 0)
        {
            _last = nullptr;
        }
    }

    void insertAt(size_t index, T val)
    {
        if (index > _size)
        {
            throw std::out_of_range("Index out of range");
        }

        if (index == 0)
        {
            pushFront(val);
            return;
        }

        if (index == _size)
        {
            pushBack(val);
            return;
        }

        Node *n = _root;

        for (size_t i = 0; i < index - 1; ++i)
        {
            n = n->child;
        }

        Node *newNode = new Node(val);
        newNode->child = n->child;
        n->child = newNode;
        ++_size;
    }

    void eraseAt(size_t index)
    {
        if (index >= _size)
        {
            throw std::out_of_range("Index out of range");
        }

        if (index == 0)
        {
            popFront();
            return;
        }

        if (index == _size - 1)
        {
            popBack();
            return;
        }

        Node *n = _root;

        for (size_t i = 0; i < index - 1; ++i)
        {
            n = n->child;
        }

        Node *toDelete = n->child;
        n->child = toDelete->child;
        delete toDelete;
        --_size;
    }

    void setAt(size_t index, T val)
    {
        if (index >= _size)
        {
            throw std::out_of_range("Index out of range");
        }

        Node *n = _root;

        for (size_t i = 0; i < index; ++i)
        {
            n = n->child;
        }

        n->content = val;
    }

    void insertVectorAt(size_t index, const std::vector<T> &data)
    {
        if (index > _size)
        {
            throw std::out_of_range("Index out of range");
        }

        Node *n = _root;

        for (size_t i = 0; i < index - 1; ++i)
        {
            n = n->child;
        }

        for (const auto &val : data)
        {
            Node *newNode = new Node(val);
            if (n != nullptr)
            {
                newNode->child = n->child;
                n->child = newNode;
                n = newNode;
            }
            else
            {
                if (_last != nullptr)
                {
                    _last->child = newNode;
                    _last = newNode;
                }
                else
                {
                    _root = newNode;
                    _last = newNode;
                }
                n = newNode;
            }
            ++_size;
        }
    }

    void eraseRange(size_t index, size_t count)
    {
        if (index >= _size)
        {
            return;
        }
        if (index + count > _size)
        {
            count = _size - index;
        }

        Node *n = _root;

        for (size_t i = 0; i < index - 1; ++i)
        {
            n = n->child;
        }

        Node *toDelete = n->child;
        for (size_t i = 0; i < count; ++i)
        {
            Node *next = toDelete->child;
            delete toDelete;
            toDelete = next;
            --_size;
        }
    }

    size_t size() const
    {
        return _size;
    }

    T at(size_t index) const
    {
        if (index >= _size)
        {
            throw std::out_of_range("Index out of range");
        }

        Node *n = _root;

        for (size_t i = 0; i < index; ++i)
        {
            n = n->child;
        }

        return n->content;
    }

    void clear()
    {
        Node *n = _root;

        while (n != nullptr)
        {
            n = _root->child;
            delete _root;
            _root = n;
        }

        _last = nullptr;
        _size = 0;
    }

    // Disable copy constructor and copy assignment operator
    LinkedList(const LinkedList<T> &other) = delete;
    LinkedList<T> &operator=(const LinkedList<T> &other) = delete;

    // Enable move constructor and move assignment operator
    LinkedList(LinkedList<T> &&other) noexcept
        : _root(other._root), _last(other._last), _size(other._size)
    {
        other._root = nullptr;
        other._last = nullptr;
        other._size = 0;
    }
    LinkedList<T> &operator=(LinkedList<T> &&other) noexcept
    {
        if (this != &other)
        {
            clear();

            _root = other._root;
            _last = other._last;
            _size = other._size;

            other._root = nullptr;
            other._last = nullptr;
            other._size = 0;
        }
        return *this;
    }
};

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