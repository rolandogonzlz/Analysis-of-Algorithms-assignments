#include <iostream>
#include <list>
#include <stdexcept>
#include <cstddef>

template <typename T>
class MyStack
{
private:
    std::list<T> data;

public:
    void push(const T& value)
    {
        data.push_back(value);
    }

    void pop()
    {
        if (data.empty())
        {
            throw std::underflow_error(
                "Cannot pop from an empty stack.");
        }

        data.pop_back();
    }

    const T& top() const
    {
        if (data.empty())
        {
            throw std::underflow_error(
                "The stack is empty.");
        }

        return data.back();
    }

    bool empty() const
    {
        return data.empty();
    }

    std::size_t size() const
    {
        return data.size();
    }
};

int main()
{
    MyStack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);

    std::cout << "Stack size: "
              << stack.size()
              << '\n';

    std::cout << "Top: "
              << stack.top()
              << '\n';

    stack.pop();

    std::cout << "Top after pop: "
              << stack.top()
              << '\n';

    std::cout << "\nRemoving the remaining elements:\n";

    while (!stack.empty())
    {
        std::cout << stack.top() << '\n';
        stack.pop();
    }

    return 0;
}