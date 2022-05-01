/*
Given a Binary Tree A containing N nodes.

You need to find the path from Root to a given node B.

NOTE:

No two nodes in the tree have same data values.
You can assume that B is present in the tree A and a path always exists. 
*/

vector<int>ans;
void DFS(TreeNode* root ,vector<int> v, int p)
 {
    if(!root) return;
    v.push_back(root->val);
    if(p==root->val)
    {
        ans = v;
        return;
    }
    DFS(root->left,v, p);
    DFS(root->right,v, p);
}
vector<int> Solution::solve(TreeNode* A, int B) 
{
    vector<int>res;
    DFS(A, res, B);
    return ans;
}

