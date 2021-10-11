class Solution
{
    public:
    void solve(Node* root, vector<int>&v, int level)
    {
        if(root==NULL) return;
        if(v.size()==level)
            v.push_back(root->data);
        solve(root->right, v, level+1);
        solve(root->left, v, level+1);
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int>v;
       if(root==NULL) return v;
       solve(root, v, 0);
       return v;
    }
};

