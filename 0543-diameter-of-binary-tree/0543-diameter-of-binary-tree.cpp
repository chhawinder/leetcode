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
    int d=0;
    int help(TreeNode*root){
        if(root==nullptr)return 0;
        if(root->left==nullptr&&root->right==nullptr)return 1;
        int r=help(root->right);
        int l=help(root->left);
        d=max(d,l+r);
        return max(l,r)+1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
     help(root); 
        
        return d;
    }
};