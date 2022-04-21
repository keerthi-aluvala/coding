/* Maximum sum of Non-adjacent nodes */

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    unordered_map<Node*, int>mp;
    int solve(Node* root)
    {
        if(!root) return 0;
        if(mp[root]) return mp[root];
        int inc = root->data;
        if(root->left)
        {
            inc += solve(root->left->left);
            inc += solve(root->left->right);
        }
        if(root->right)
        {
            inc += solve(root->right->left);
            inc += solve(root->right->right);
        }
        int exc = solve(root->left)+solve(root->right);
        mp[root] = max(inc,exc);
        return mp[root];
    }
    int getMaxSum(Node *root) 
    {
        return solve(root);
    }
};

