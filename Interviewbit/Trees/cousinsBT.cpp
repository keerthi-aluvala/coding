vector<int> printCousins(Node* root, Node* find)
    {
        //code here
        queue<Node *> q;
        q.push(root);
        int marker=false;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                Node *t=q.front();
                q.pop();
                if(t->left==find || t->right==find)
                {
                    marker=true;
                }
                else
                {
                    if(t->left)
                    {
                        q.push(t->left);
                    }
                    if(t->right)
                    {
                        q.push(t->right);
                    }
                }
                
            }
            if(marker)
            {
                break;
            }
        }
        if(q.empty())
        {
            return {-1};
        }
        vector<int> ans;
        while(!q.empty())
        {
            Node *t=q.front();
            ans.push_back(t->data);
            q.pop();
        }
        return ans;
    }
