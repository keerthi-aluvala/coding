/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

class Solution {
public:
    bool solve(TreeNode* root, long l, long r)
    {
        if(root==NULL) return true;
        if(root->val<=l || root->val>=r)
            return false;
        return (solve(root->left,l,root->val) && solve(root->right,root->val,r));
    }
    bool isValidBST(TreeNode* root) 
    {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};
