#include <iostream>
using namespace std;
class binaryTree
{
public:
    binaryTree() { root = nullptr; }

    void populate()
    {
        cout << "enter the root node value";
        int value;
        cin >> value;
        root = new Node(value);
        populate(root);
    }

private:
    class Node
    {
    private:
        int value;
        Node *left;
        Node *right;

    public:
        Node(int value)
        {
            this->value = value;
        }
    };
    Node *root;

    void populate(Node *node) {}
};