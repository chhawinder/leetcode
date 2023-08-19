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
    TreeNode* help(vector<int>& nums,int l,int h){
        if(l>h)return nullptr;
        if(l==h){
            TreeNode* root=new TreeNode(nums[l]);
            return root;
        }
        int mid=(h-l)/2+l;
        TreeNode*le=help(nums,l,mid-1);
        TreeNode*ri=help(nums,mid+1,h);
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=le;
        root->right=ri;
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return help(nums,0,nums.size()-1);
    }
};