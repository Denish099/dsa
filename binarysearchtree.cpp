#include <iostream>
using namespace std;

class binarySearchTree
{
public:
    binarySearchTree()
    {
        root = nullptr;
    }
    void display()
    {
        display(root, 0);
    }
    void setRoot()
    {
        if (root != nullptr)
        {
            cout << "Root already exists!" << endl;
            return;
        }

        int value;
        cout << "Enter the value of root node: ";
        cin >> value;
        root = new Node(value);
    }

    void populate()
    {
        if (root == nullptr)
        {
            cout << "Set the root first using setRoot()." << endl;
            return;
        }

        char insertMore;
        int value;

        do
        {
            cout << "Do you want to insert another node? (y/n): ";
            cin >> insertMore;

            if (insertMore == 'y' || insertMore == 'Y')
            {
                cout << "Enter the value to insert: ";
                cin >> value;
                insert(root, value);
            }

        } while (insertMore == 'y' || insertMore == 'Y');
    }

    void inorder()
    {
        cout << "Inorder traversal: ";
        inorder(root);
        cout << endl;
    }

private:
    class Node
    {
    public:
        int value;
        Node *left, *right;

        Node(int value)
        {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
    };

    Node *root;

    void insert(Node *node, int value)
    {
        if (value < node->value)
        {
            if (node->left == nullptr)
            {
                node->left = new Node(value);
            }
            else
            {
                insert(node->left, value);
            }
        }
        else
        {
            if (node->right == nullptr)
            {
                node->right = new Node(value);
            }
            else
            {
                insert(node->right, value);
            }
        }
    }

    void inorder(Node *node)
    {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

    void display(Node *node, int level)
    {
        if (node == nullptr)
            return;

        display(node->right, level + 1);

        for (int i = 0; i < level; i++)
            cout << "        ";

        cout << node->value << endl;

        display(node->left, level + 1);
    }
};

int main()
{
    binarySearchTree bst;

    bst.setRoot();
    bst.populate();
    bst.display();

    return 0;
}
