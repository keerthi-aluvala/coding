/*  Left View of Tree  */

void solve(bool* levels, Node* root, int curr, vector<int>&v)
{
    if(!root) return ;
    if(levels[curr]==false)
    {
        levels[curr] = true;
        v.push_back(root->data);
    }
    solve(levels,root->left,curr+1,v);    
    solve(levels,root->right,curr+1,v);
}
vector<int> leftView(Node *root)
{
   vector<int>v;
   bool levels[202] = {false};
   solve(levels, root, 0, v);
   return v;
}
