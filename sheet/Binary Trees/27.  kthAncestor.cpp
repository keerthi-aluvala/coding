/* kth ancestor of a node */

Node* solve(Node* root,int x, int& k)
{
	if(!root) return NULL;
	Node* l = solve(root->left,x,k);
	Node* r = solve(root->right,x,k);
	if(root->data==x || l!=NULL || r!=NULL)
	{
		if(k>0) k--;
		else
		{
			cout<<root->data;
			return NULL;
		}
		return root;
	}
}
