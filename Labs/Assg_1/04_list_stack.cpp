#include <iostream>
#include <list>

int main()
{
    std::list<int> myStack;

    std::cout << "Pushing elements...\n";

    myStack.push_back(10);
    myStack.push_back(20);
    myStack.push_back(30);
    myStack.push_back(40);
    myStack.push_back(50);
    myStack.push_back(60);
    myStack.push_back(70);
    myStack.push_back(80);
    myStack.push_back(90);

    std::cout << "Top element: "
              << myStack.back()
              << '\n';

    std::cout << "Removing top element...\n";

    myStack.pop_back();

    std::cout << "New top element: "
              << myStack.back()
              << '\n';

    std::cout << "\nRemoving all elements:\n";

    while (!myStack.empty())
    {
        std::cout << myStack.back() << '\n';
        myStack.pop_back();
    }

    return 0;
}