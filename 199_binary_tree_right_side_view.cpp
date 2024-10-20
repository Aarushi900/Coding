#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    void help(TreeNode *node, int level, vector<int> &res)
    {
        if (node == NULL)
        {
            return;
        }
        if (res.size() == level)
        {
            res.push_back(node->val);
        }
        help(node->right, level + 1, res);
        help(node->left, level + 1, res);
        return;
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        help(root, 0, res);
        return res;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(5);
    Solution sol;
    vector<int> res = sol.rightSideView(root);
    for (auto i : res)
    {
        cout << i << " ";
    }
}