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
    int help(TreeNode* root,int mx){
        if(root==nullptr)return 0;
        if(mx>root->val){
            return help(root->left,mx)+help(root->right,mx);
        }else{
            return help(root->left,root->val)+help(root->right,root->val)+1;
        }
    }
    int goodNodes(TreeNode* root) {
        int l=help(root->left,root->val);
        int r=help(root->right,root->val);
        return l+r+1;
        
    }
};