/* ZigZag Tree Traversal */

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int>v;
        if(root==NULL) return v;
    	queue<Node*>q;
    	int flag=0;
    	q.push(root);
    	while(!q.empty())
    	{
    	    int currSize = q.size();
    	    vector<int>temp1;
    	    while(currSize>0)
    	    {
    	        Node* temp2 = q.front();
    	        q.pop();
    	        temp1.push_back(temp2->data);
    	        if(temp2->left) q.push(temp2->left);
    	        if(temp2->right) q.push(temp2->right);
    	        currSize--;
    	    }
    	    if(flag==1)
    	    {
    	        reverse(temp1.begin(),temp1.end());
    	    }
    	    for(auto it: temp1)
    	        v.push_back(it);
    	    flag = 1-flag;
    	}
    	return v;
    }
};
