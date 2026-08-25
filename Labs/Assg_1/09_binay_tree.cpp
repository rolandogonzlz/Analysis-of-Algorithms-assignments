#include <iostream>

class BinarySearchTree
{
private:
    struct Node
    {
        int data;
        Node* left;
        Node* right;

        explicit Node(int value)
            : data(value),
              left(nullptr),
              right(nullptr)
        {
        }
    };

    Node* root;

    Node* insert(Node* node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insert(node->right, value);
        }

        return node;
    }

    void inorder(Node* node) const
    {
        if (node == nullptr)
        {
            return;
        }

        inorder(node->left);

        std::cout << node->data << " ";

        inorder(node->right);
    }

    void preorder(Node* node) const
    {
        if (node == nullptr)
        {
            return;
        }

        std::cout << node->data << " ";

        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) const
    {
        if (node == nullptr)
        {
            return;
        }

        postorder(node->left);
        postorder(node->right);

        std::cout << node->data << " ";
    }

    bool search(Node* node, int value) const
    {
        if (node == nullptr)
        {
            return false;
        }

        if (node->data == value)
        {
            return true;
        }

        if (value < node->data)
        {
            return search(node->left, value);
        }

        return search(node->right, value);
    }

    void destroy(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }

        destroy(node->left);
        destroy(node->right);

        delete node;
    }

public:
    BinarySearchTree()
        : root(nullptr)
    {
    }

    ~BinarySearchTree()
    {
        destroy(root);
    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    void printInorder() const
    {
        inorder(root);
        std::cout << '\n';
    }

    void printPreorder() const
    {
        preorder(root);
        std::cout << '\n';
    }

    void printPostorder() const
    {
        postorder(root);
        std::cout << '\n';
    }

    bool contains(int value) const
    {
        return search(root, value);
    }
};

int main()
{
    BinarySearchTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Inorder traversal:\n";
    tree.printInorder();

    std::cout << "\nPreorder traversal:\n";
    tree.printPreorder();

    std::cout << "\nPostorder traversal:\n";
    tree.printPostorder();

    std::cout << "\nSearching for 40: ";

    if (tree.contains(40))
    {
        std::cout << "Found\n";
    }
    else
    {
        std::cout << "Not found\n";
    }

    std::cout << "Searching for 100: ";

    if (tree.contains(100))
    {
        std::cout << "Found\n";
    }
    else
    {
        std::cout << "Not found\n";
    }

    return 0;
}