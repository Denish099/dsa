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

    void display()
    {
        display(root, " ");
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
            left = nullptr;
            right = nullptr;
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
    void display(Node *node, string indent)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << indent << node->value;
        display(node->left, indent + "\t");
        display(node->right, indent + "\t");
    }
};

int main()
{
    binaryTree tree;
    tree.populate();

    cout << "tree structure" << endl;

    tree.display();

    return 0;
}