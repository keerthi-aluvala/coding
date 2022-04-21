/* Check for BST */

int solve(Node* root, int min, int max)
    {
        if(root==NULL) return 1;
        if(root->data<min || root->data>max) return 0;
        return solve(root->left,min,root->data-1) && solve(root->right, root->data+1,max);
    }
    bool isBST(Node* root) 
    {
        return solve(root,INT_MIN,INT_MAX);
    }
