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
    pair<int,int> help(TreeNode* root,int &sol){
        if(root==nullptr)return {0,0};
        int mn=root->val,mx=root->val;
        if(root->left){
            pair<int,int>l=help(root->left,sol);
            sol=max(sol,max(abs(root->val-l.first),abs(root->val-l.second)));
            mn=min(mn,l.first);
            mx=max(mx,l.second);
        }
        if(root->right){
            pair<int,int>r=help(root->right,sol);
            sol=max(sol,max(abs(root->val-r.first),abs(root->val-r.second)));
            mn=min(mn,r.first);
            mx=max(mx,r.second);
        }
        
        
        
        return {mn,mx};
    }
    int maxAncestorDiff(TreeNode* root) {
        
        int sol=INT_MIN;
        help(root,sol);
        return sol;
    }
};