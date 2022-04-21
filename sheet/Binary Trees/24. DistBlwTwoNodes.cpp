/* Min distance between two given nodes of a Binary Tree */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* LCA(Node* root, int a, int b)
    {
        if(!root) return NULL;
        if(root->data==a || root->data==b) return root;
        Node* l = LCA(root->left, a, b);
        Node* r = LCA(root->right, a, b);
        if(l && r) return root;
        if(l) return l;
        else return r;
    }
    int solve(Node* root, int x)
    {
        if(!root) return 0;
        if(root->data==x) return 1;
        int a = solve(root->left, x);
        int b = solve(root->right, x);
        if(!a && !b) return 0;
        else return a+b+1;
    }
    int findDist(Node* root, int a, int b) 
    {
        Node* lca = LCA(root,a,b);
        int x = solve(lca, a);
        int y = solve(lca, b);
        return x+y-2;
    }
};
