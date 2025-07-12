class binarySearchTree
{
public:
private:
    class Node
    {
    public:
        int value;
        Node *left;
        Node *right;

    private:
        Node(int value)
        {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
    };
};