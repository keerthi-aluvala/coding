/* Find largest subtree sum in a tree */

maxx=0;
void solve(Node* root)
{
	if(!root) return 0;
	int l = solve(root->left);
	int r = solve(root->right);
	maxx = max(maxx, l+r+root->data);
	return l+r+root->data;
}
