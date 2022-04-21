/* Populate Inorder Successor for all nodes */

class Solution
{
public:
    Node* next = NULL;
    void populateNext(Node *root)
    {
        if(!root) return;
        populateNext(root->right);
        root->next = next;
        next = root;
        populateNext(root->left);
    }
};
