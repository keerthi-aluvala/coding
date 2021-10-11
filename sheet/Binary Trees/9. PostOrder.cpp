/* PostOrder */

vector<int> PostOrder(Node* root)
{
	vector<int>v;
	stack<Node*>s1, s2;
	s1.push(root);
	while(!s1.empty())
	{
		Node* temp = s1.top(); s1.pop();
		s2.push(temp);
		if(temp->left) s1.push(temp->left);
		if(temp->right) s2.push(temp->right);
	}
	while(!s2.empty())
	{
		Node* temp = s2.top(); s2.pop();
		v.push_back(temp->data);
	}
	return v;
}

void PostOrder(Node* root)
{
	if(root==NULL) return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data;
}
