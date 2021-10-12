/* Boundary Traversal of binary tree */

class Solution {
public:
    void leftTree(Node* root, vector<int>&res)
    {
        if(!root) return;
        if(root->left)
        {
            res.push_back(root->data);
            leftTree(root->left, res);
        }
        else if(root->right)
        {
            res.push_back(root->data);
            leftTree(root->right, res);
        }
    }
    void leaves(Node* root, vector<int>&res)
    {
        if(!root) return;
        if(!root->left && !root->right) res.push_back(root->data);
        leaves(root->left, res);
        leaves(root->right, res);
    }
    void rightTree(Node* root, vector<int>&res)
    {
        if(!root) return;
        if(root->right)
        {
            rightTree(root->right, res);
            res.push_back(root->data);
        }
        else if(root->left)
        {
            rightTree(root->left, res);
            res.push_back(root->data);
        }
    }
    
    vector<int> printBoundary(Node *root)
    {
        vector<int>res;
        res.push_back(root->data);
        leftTree(root->left, res);
        leaves(root, res);
        rightTree(root->right, res);
        return res;
    }
};
