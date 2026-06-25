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
    int height(TreeNode *root,int &valid)
    {
        if(root == nullptr)
        return 0;

        int left = height(root->left,valid);
        int right = height(root->right,valid);
        if(abs(left-right)>1)
        valid=0;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        int valid = 1;
        height(root,valid);
        return valid;
    }
};
