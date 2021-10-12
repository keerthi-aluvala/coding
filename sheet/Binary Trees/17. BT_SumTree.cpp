/* Convert BT to Sum Tree */

int solve(Node* root)
    {
        if(!root) return 0;
        
        int l = solve(root->left);
        int r = solve(root->right);
        int x = root->data;
        root->data = l+r;
        return l+r+x;
    }
    
    void toSumTree(Node *root)
    {
        // Your code here
        solve(root);
    }
