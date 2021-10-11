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





void solve(Node* root, vector<int>&v, int level)
{
    if(root==NULL) return;
    if(v.size()==level)
        v.push_back(root->data);
    solve(root->left, v, level+1);
    solve(root->right, v, level+1);
}
vector<int> leftView(Node *root)
{
   // Your Code here
   vector<int>v;
   if(root==NULL) return v;
   solve(root, v, 0);
   return v;
}
