/* PreOrder */

vector<int> PreOrder(Node* root)
{
	vector<int>v;
	stack<Node*>st;
	st.push(root);
	while(!st.empty())
	{
		Node* temp = st.top(); st.pop();
		v.push_back(temp->data);
		if(temp->right)
			st.push(temp->right);
		if(temp->left)
			st.push(temp->left);
	}
	return v;
}


void PreOrder(Node* root)
{
	if(root==NULL) return;
	cout<<root->data;
	PreOrder(root->left);
	PreOrder(root->right);
}
