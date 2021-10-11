/* Diameter of Binary tree */

int height(struct Node* root)
{
    if(root==NULL) return 0;
    int left = 1+height(root->left);
    int right = 1+height(root->right);
    return max(left,right);
}
// Function to return the diameter of a Binary Tree.
int diameter(struct Node* root) 
{
    if(root==NULL) return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
    return max(lheight+rheight+1, max(ldiameter,rdiameter));
}




/* O(n) solution */
int solve(Node* root, int& ans)
{
    if(root==NULL) return 0;
    int lh = solve(root->left, ans);
    int rh = solve(root->right, ans);
    ans = max(ans, lh+rh+1);
    return 1+max(lh,rh);
}

// Function to return the diameter of a Binary Tree.
int diameter(Node* root) 
{
    if(root==NULL) return 0;
    int ans = INT_MIN;
    solve(root, ans);
    return ans;
}
