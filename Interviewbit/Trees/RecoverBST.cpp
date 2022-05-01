/* Two elements of a binary search tree (BST) are swapped by mistake.

Tell us the 2 values swapping which the tree will be restored.*/


vector swapped;

void inorder(TreeNode* root, int& prev)
{
	if(!root) return;
	
	inorder(root->left,prev);
	if(prev!=INT_MIN && prev>root->val)
	{
	    swapped.push_back(prev);
	    swapped.push_back(root->val);
	}
	prev=root->val;
	inorder(root->right,prev);
}

vector Solution::recoverTree(TreeNode* A) 
{
	swapped.clear();
	int prev=INT_MIN;
	inorder(A, prev);
	sort(swapped.begin(),swapped.end());
	vector<int> ans = {swapped[0], swapped[swapped.size()-1]};
	return ans;	
}
