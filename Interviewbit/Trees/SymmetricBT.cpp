bool f(TreeNode* p, TreeNode* q)
 {
     if(p==NULL && q==NULL) return true;
     if(p==NULL || q==NULL) return false;
     if(p->val!=q->val) return false;
     return f(p->left,q->right) && f(p->right, q->left);
 }
