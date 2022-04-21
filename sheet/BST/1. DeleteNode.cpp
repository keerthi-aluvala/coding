/* 450. Delete Node in a BST */

class Solution {
public:
    TreeNode* inSucc(TreeNode* root)
    {
        TreeNode* temp = root->right;
        while(temp->left) temp=temp->left;
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root) return NULL;
        if(key>root->val) 
        {
            root->right = deleteNode(root->right,key);
            return root;
        }
        else if(key<root->val) 
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else
        {
            if(!root->right && !root->left)
            {
                delete(root);
                return NULL;
            }
            else if(!root->right && root->left)
            {
                TreeNode* temp = root->left;
                delete(root);
                return temp;
            }
            else if(!root->left && root->right)
            {
                TreeNode* temp = root->right;
                delete(root);
                return temp;
            }
            else
            {
                TreeNode* p = inSucc(root);
                swap(root->val,p->val);
                root->right = deleteNode(root->right,key);
                return root;
            }

        }
    }
};
