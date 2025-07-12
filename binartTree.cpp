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
    public:
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

    void populate(Node *node)
    {

        char choice;

        cout << "Does " << node->value << " have a left child? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            cout << "Enter the value of left child of " << node->value << ": ";
            int leftValue;
            cin >> leftValue;
            node->left = new Node(leftValue);
            populate(node->left);
        }

        cout << "Does " << node->value << " have a right child? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            cout << "Enter the value of right child of " << node->value << ": ";
            int rightValue;
            cin >> rightValue;
            node->right = new Node(rightValue);
            populate(node->right);
        }
    }
};