// Maximum Depth of a BT

int Solution::maxDepth(TreeNode* root) 
{
    if(root==NULL) return 0;
    int l = 1+maxDepth(root->left);
    int r = 1+maxDepth(root->right);
    return max(l,r);
}

