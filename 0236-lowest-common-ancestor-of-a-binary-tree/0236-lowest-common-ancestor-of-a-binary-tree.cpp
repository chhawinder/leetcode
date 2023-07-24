/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool help(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode*& sol){
        if(root==nullptr)return false;
        if(root==p||root==q){
            if(help(root->left,p,q,sol)||help(root->right,p,q,sol)){
                sol=root;
            }
            return true;
        }
        bool l=help(root->left,p,q,sol);
        bool r=help(root->right,p,q,sol); 
        if(l&&r){
            sol=root;

        }
        if(l||r)return true;
        return false;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode*sol;
        help(root,p,q,sol);
        return sol;
    }
};