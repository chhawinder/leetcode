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
   
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)return true;
        if(root->left==nullptr&&root->right==nullptr)return true;
        if(isValidBST(root->left)&&isValidBST(root->right)){
            bool l=true,r=true;
            if(root->left)l=root->val>root->left->val;
            if(root->right)r=root->val<root->right->val;
            if(l&&r){
                if(root->left){
                     TreeNode*temp=root->left;
                while(temp->right){
                    temp=temp->right;
                }
                if(temp->val>=root->val)return false;
                }
                if(root->right){
                     TreeNode*temp=root->right;
                while(temp->left)temp=temp->left;
                if(temp->val<=root->val)return false;
                
                }
               
               
                return true;
            }
        }
        return false;
    }
};