/* Bottom View of Binary Tree */

class Solution {
  public:
    vector <int> bottomView(Node *root) 
    {
        vector<int>v;
        if(root==NULL) return v;
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            Node* temp = p.first;
            mp[p.second] = temp->data;
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
