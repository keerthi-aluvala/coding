//Given a binary tree, find its minimum depth. 
//The minimum depth is the number of nodes along the shortest path 
//from the root node down to the nearest leaf node. 

int Solution::minDepth(TreeNode* root) 
{
    if(root==NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    int l = INT_MAX, r = INT_MAX;
    if(root->left) l = 1+minDepth(root->left);
    if(root->right) r = 1+minDepth(root->right);
    return min(l,r);
}
