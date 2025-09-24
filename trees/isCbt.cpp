#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        if (!root)
            return true;

        queue<TreeNode *> q;
        q.push(root);
        bool nullSeen = false;

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr == nullptr)
            {
                nullSeen = true;
            }
            else
            {
                if (nullSeen)
                {
                    return false;
                }
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return true;
    }
};