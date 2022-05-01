// Sorted Array To Balanced BST

TreeNode* f(vector<int>v)
 {
     if(v.size()==0) return NULL;
     int n = v.size()/2;
     TreeNode* root = new TreeNode(v[n]);
     root->left = f(vector<int>(v.begin(),v.begin()+n));
     root->right = f(vector<int>(v.begin()+n+1,v.end()));
     return root;
 }
