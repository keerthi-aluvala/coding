/* Top View of Binary Tree */

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>v;
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        q.push({root, 0});
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            Node* temp = p.first;
            if(mp.find(p.second)==mp.end())
            {
                mp[p.second] = temp->data;
            }
            if(temp->left) q.push({temp->left,p.second-1});
            if(temp->right) q.push({temp->right,p.second+1});
        }
        for(auto p: mp)
        {
            v.push_back(p.second);
        }
        return v;
    }

};

