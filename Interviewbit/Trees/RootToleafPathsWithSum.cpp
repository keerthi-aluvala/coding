// Root to Leaf Paths With Sum

//Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

void DFS(TreeNode* root ,vector<int> v,vector<vector<int>> &final, int sum)
 {
    if(!root) return;
    v.push_back(root->val);
    if(!root->left && !root->right && sum==root->val)
    {
        final.push_back(v);
    }
    DFS(root->left,v,final, sum-root->val);
    DFS(root->right,v,final, sum-root->val);
}
vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) 
{
	vector<vector<int>> final;
    if(!root) return final;
    vector<int> v;
    DFS(A,v,final, B); 
    return final;
}
