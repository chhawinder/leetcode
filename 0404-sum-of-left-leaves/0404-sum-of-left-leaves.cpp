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
    bool check(TreeNode* root){
        if(root==nullptr)return false;
        if(root->left==nullptr&&root->right==nullptr)return true;
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==nullptr)return 0;
        int sum=0;
        if(check(root->left))sum+=root->left->val;
        sum=sum+sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
        return sum;
    }
};