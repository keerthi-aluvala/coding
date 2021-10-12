/* Duplicate subtree in Binary Tree */

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    unordered_map<string,int>mp;
    string solve(Node* root)
    {
        if(!root) return "$";
        string s = "";
        if(!root->left && !root->right)
        {
            s = to_string(root->data);
            return s;
        }
        s += to_string(root->data);
        s += solve(root->left);
        s += solve(root->right);
        mp[s]++;
        return s;
    }
    int dupSub(Node *root) 
    {
        mp.clear();
        solve(root);
        for(auto x: mp)
        {
            if(x.second>=2) return true;
        }
        return false;
    }
};

