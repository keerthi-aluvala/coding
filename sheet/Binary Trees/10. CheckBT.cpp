/* check a tree is balanced or not */

bool isBalanced(Node* root)
{
	if(root==NULL) return true;
	else if(!(isBalanced(root->left)&&isBalanced(root->right))) return false;
	return abs(depth(root->right)-depth(root->left) <=1);
}
int depth(Node* root)
{
	if(root==NULL) return 0;
	else return 1+max(depth(root->left),depth(root->right));
}



class Solution {
public:
    int checkbalanced(struct TreeNode *root,bool &ans)
    {
        if(root == NULL)
        {
            return 0;
        }
        int lh=checkbalanced(root->left,ans);
        int rh=checkbalanced(root->right,ans);
        if(abs(lh-rh) > 1)
        {
            ans=false;
        }
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        checkbalanced(root,ans);
        return ans;
    }
};
