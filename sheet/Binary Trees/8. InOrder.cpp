/* InOrder */

vector<int> InOrder(Node* root)
{
	vector<int>v;
	stack<Node*>st;
	st.push(root);
	Node* curr = root;
	while(!st.empty() || curr!=NULL)
	{
		while(curr!=NULL)
		{
			st.push(curr);
			curr = curr->left;
		}
		curr = st.top(); st.pop();
		v.push_back(curr->data);
		curr = curr->right;
	}
	return v;
}

void InOrder(Node* root)
{
	if(root==NULL) return;
	InOrder(root->left);
	cout<<root->data;
	InOrder(root->right);
}
