/* Check if a sumTree or not */

class Solution
{
    public:
    int flag=1;
    int solve(Node* root)
    {
        if(!root) return 0;
        if(!root->left && !root->right) return root->data;
        if(flag==0) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        if((l+r)!=root->data)
            flag=0;
        return l+r+root->data;
    }
    bool isSumTree(Node* root)
    {
        flag=1;
        solve(root);
        return flag;
    }
};
