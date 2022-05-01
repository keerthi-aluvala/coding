/*
Given two Binary Trees A and B, you need to merge them in a single binary tree.

The merge rule is that if two nodes overlap, then sum of node values is the new value of the merged node.

Otherwise, the non-null node will be used as the node of new tree.
*/

TreeNode* Solution::solve(TreeNode* t1, TreeNode* t2) 
{
    if(t1==NULL) return t2;
    if(t2==NULL) return t1;
    t1->val += t2->val;
    t1->left = solve(t1->left, t2->left);
    t1->right = solve(t1->right, t2->right);
    return t1;
}

