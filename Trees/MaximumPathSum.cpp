/* 124. Binary Tree Maximum Path Sum 

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any path.


*/

class Solution {
public:
    int solve(TreeNode* root, int& result)
    {
        if(!root) return 0;
        int left = solve(root->left,result);
        int right = solve(root->right,result);
        int mx = max(max(left,right)+root->val,root->val);
        result = max(result,max(mx,left+right+root->val));
        return mx;
    }
    int maxPathSum(TreeNode* root) 
    {
        int result = INT_MIN;
        solve(root,result);
        return result;
    }
};
