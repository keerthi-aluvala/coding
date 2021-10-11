/* Level order traversal */

vector<int> levelOrder(Node* root)
{
  //Your code here
  vector<int>v;
  queue<Node*>q;
  q.push(root);
  while(!q.empty())
  {
      int currSize = q.size();
      while(currSize>0)
      {
          Node* temp = q.front();
          q.pop();
          v.push_back(temp->data);
          if(temp->left)
            q.push(temp->left);
          if(temp->right)
            q.push(temp->right);
        currSize--;
      }
  }
  return v;
}
