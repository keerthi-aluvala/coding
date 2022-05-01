//Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that 
//adding up all the values along the path equals the given sum.

int Solution::hasPathSum(TreeNode* root, int sum) 
{
    if(root==NULL) return false;
    if(root->val==sum && !root->left && !root->right) return true;
    bool l = hasPathSum(root->left, sum-root->val);
    bool r = hasPathSum(root->right, sum-root->val);
    return l || r;
}

