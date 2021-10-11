/* Reverse Level Order Traversal */

vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>>res;
        stack<vector<int>>st;
        queue<TreeNode*>q;
        q.push(root);
        if(root==NULL) return res;
        while(!q.empty())
        {
            int currSize = q.size();
            vector<int>v;
            while(currSize>0)
            {
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                currSize--;
            }
            st.push(v);
        }
        while(!st.empty())
        {
            vector<int>temp = st.top();
            st.pop();
            res.push_back(temp);
        }
        return res;
    }
