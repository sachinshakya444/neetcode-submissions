/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int dfs(TreeNode* node,int maxSofar)
    {
        if(!node)
        return 0;

        int good = node->val>=maxSofar?1:0;
        int newMax = max(node->val,maxSofar);

        good = good + dfs(node->left,newMax);
        good = good + dfs(node->right,newMax);

        return good;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);
    }
};
