//Given a Binary Tree, check if all leaves are at same level or not
bool check(Node *root)
    {
        unordered_map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int currSize = q.size();
            while(currSize>0)
            {
                auto x = q.front();
                q.pop();
                Node* temp = x.first;
                int level = x.second;
                if(temp->left) q.push({temp->left,level+1});
                if(temp->right) q.push({temp->right,level+1});
                if(!temp->left && !temp->right)
                {
                    if(mp.find(level)!=mp.end())
                        mp[level]++;
                    else
                        mp[level] = 1;
                }
                currSize--;
            }
        }
        //for(auto x: mp)
        //    cout<<x.first<<" "<<x.second<<endl;
        if(mp.size()>1) return false;
        return true;
    }
