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
                root = insert(root, value);
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
            height = 1;
            left = right = nullptr;
        }
    };

    Node *root;

    int getHeight(Node *node)
    {
        return node ? node->height : 0;
    }

    int getBalance(Node *node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node *insert(Node *node, int value)
    {
        if (node == nullptr)
            return new Node(value);

        if (value < node->value)
            node->left = insert(node->left, value);
        else if (value > node->value)
            node->right = insert(node->right, value);
        else
            return node; // duplicate values not allowed

        // Update height
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Balance the node
        int balance = getBalance(node);

        // Left Left
        if (balance > 1 && value < node->left->value)
            return rightRotate(node);

        // Right Right
        if (balance < -1 && value > node->right->value)
            return leftRotate(node);

        // Left Right
        if (balance > 1 && value > node->left->value)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left
        if (balance < -1 && value < node->right->value)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
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
