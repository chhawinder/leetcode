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
    bool areTreesIdentical(TreeNode* root1, TreeNode* root2) {
    // If both trees are empty, they are identical
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
  
    // If either tree is empty, they are not identical
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }
  
    // Compare the current nodes and recursively compare their children
    return (root1->val == root2->val) &&
           areTreesIdentical(root1->left, root2->left) &&
           areTreesIdentical(root1->right, root2->right);
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL)return true;
        if(root==NULL)return false;
        if(areTreesIdentical(root,subRoot))return true;
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};