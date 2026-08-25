#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <vector>

int main()
{
    // ------------------------------------
    // 1. std::stack
    // ------------------------------------

    std::stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "std::stack:\n";

    while (!stack.empty())
    {
        std::cout << stack.top() << " ";
        stack.pop();
    }

    std::cout << "\n\n";

    // ------------------------------------
    // 2. std::queue
    // ------------------------------------

    std::queue<int> queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    std::cout << "std::queue:\n";

    while (!queue.empty())
    {
        std::cout << queue.front() << " ";
        queue.pop();
    }

    std::cout << "\n\n";

    // ------------------------------------
    // 3. std::priority_queue
    // ------------------------------------

    std::priority_queue<int> priorityQueue;

    priorityQueue.push(30);
    priorityQueue.push(10);
    priorityQueue.push(50);
    priorityQueue.push(20);

    std::cout << "std::priority_queue:\n";

    while (!priorityQueue.empty())
    {
        std::cout << priorityQueue.top() << " ";
        priorityQueue.pop();
    }

    std::cout << "\n\n";

    // ------------------------------------
    // 4. stack using vector internally
    // ------------------------------------

    std::stack<int, std::vector<int>> vectorStack;

    vectorStack.push(100);
    vectorStack.push(200);
    vectorStack.push(300);

    std::cout << "std::stack using std::vector:\n";

    while (!vectorStack.empty())
    {
        std::cout << vectorStack.top() << " ";
        vectorStack.pop();
    }

    std::cout << "\n\n";

    // ------------------------------------
    // 5. stack using list internally
    // ------------------------------------

    std::stack<int, std::list<int>> listStack;

    listStack.push(1);
    listStack.push(2);
    listStack.push(3);

    std::cout << "std::stack using std::list:\n";

    while (!listStack.empty())
    {
        std::cout << listStack.top() << " ";
        listStack.pop();
    }

    std::cout << "\n\n";

    // ------------------------------------
    // 6. queue using list internally
    // ------------------------------------

    std::queue<int, std::list<int>> listQueue;

    listQueue.push(5);
    listQueue.push(10);
    listQueue.push(15);

    std::cout << "std::queue using std::list:\n";

    while (!listQueue.empty())
    {
        std::cout << listQueue.front() << " ";
        listQueue.pop();
    }

    std::cout << '\n';

    return 0;
}