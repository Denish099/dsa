#include <iostream>
#include <algorithm>
using namespace std;

class Avl
{
public:
    Avl()
    {
        root = nullptr;
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

    void height()
    {
        cout << "Height of tree is " << getHeight(root) << endl;
    }

    void display()
    {
        display(root, 0);
    }

    bool balanced()
    {
        return isBalanced(root);
    }

    ~Avl()
    {
        clear(root);
    }

private:
    class Node
    {
    public:
        int value;
        int height;
        Node *left;
        Node *right;

        Node(int val)
        {
            value = val;
            height = 0;
            left = right = nullptr;
        }
    };

    Node *root;

    int height(Node *node)
    {
        return getHeight(node);
    }

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
        else if (value > node->value)
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

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        rotate(node);
    }

    void rotate(Node *node)
    {
        if (height(node->left) - height(node->right) > 1)
        // left heavy
        {
            if (height(node->left->left) - height(node->left->right) > 0)
            {
                // left - left case
                rightRotate(node);
            }
            if (height(node->left->left) - height(node->left->right) < 0)
            {
                // left - left case
                leftRotate(node);
                rightRotate(node);
            }
        }
    }

    void leftRotate(Node *node) {}
    void rightRotate(Node *node) {}

    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

    int getHeight(Node *node)
    {
        return node ? node->height : -1;
    }

    void display(Node *node, int level)
    {
        if (!node)
            return;

        display(node->right, level + 1);
        for (int i = 0; i < level; ++i)
            cout << "        ";
        cout << node->value << endl;
        display(node->left, level + 1);
    }

    bool isBalanced(Node *node)
    {
        if (!node)
            return true;

        int lh = getHeight(node->left);
        int rh = getHeight(node->right);

        if (abs(lh - rh) > 1)
            return false;

        return isBalanced(node->left) && isBalanced(node->right);
    }

    void clear(Node *node)
    {
        if (!node)
            return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
};

int main()
{
    Avl bst;

    bst.setRoot();
    bst.populate();
    bst.inorder();
    bst.display();
    bst.height();

    cout << "Tree is balanced: " << (bst.balanced() ? "Yes" : "No") << endl;

    return 0;
}
