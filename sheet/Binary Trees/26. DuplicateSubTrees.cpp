/* Duplicate Subtrees */

unordered_map<string, int>mp;
vector<Node*>res;
string inorder(Node* root)
{
    if(!root) return "";
    string str = "(";
    str += inorder(root->left);
    str += to_string(root->data);
    str += inorder(root->right);
    str += ")";
    if(mp[str]==1)
        res.push_back(root);
    mp[str]++;
    return str;
}
vector<Node*> printAllDups(Node* root)
{
    mp.clear();
    res.clear();
    inorder(root);
    return res;
}
