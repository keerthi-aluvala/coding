/* Height of Binary Tree */

int height(struct Node* root)
{
    //code here
    if(root==NULL) return 0;
    int left = 1 + height(root->left);
    int right = 1 + height(root->right);
    return max(left, right);
}
