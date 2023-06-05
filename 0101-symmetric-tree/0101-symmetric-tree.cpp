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
    bool help(TreeNode* r1,TreeNode* r2){
        if(r1==NULL&&r2==NULL)return true;
        if(r1==NULL||r2==NULL)return false;
        
        if(r1->val==r2->val&&help(r1->left,r2->right)&&help(r1->right,r2->left)){
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return help(root->left,root->right);
    }
};