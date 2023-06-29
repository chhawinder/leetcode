/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int m=INT_MAX;
    int mx(TreeNode*root){
        if(root->right==nullptr)return root->val;
        return mx(root->right);
    }
    int mn(TreeNode*root){
        if(root->left==nullptr)return root->val;
        return mn(root->left);
    }
    void help(TreeNode*root){
        if(root==nullptr)return ;
        int l=INT_MAX,r=INT_MAX;
        if(root->left)l=abs(root->val-mx(root->left));
        if(root->right)r=abs(root->val-mn(root->right));
        m=min(m,min(l,r));
        help(root->left);
        help(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        help(root);
        return m;
    }
};