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
 
TreeNode* constructFromPrePost(const std::vector<int>& preorder, const std::vector<int>& postorder) {
        if (preorder.empty())
            return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        if (preorder.size() == 1)
            return root;

        int leftRootValue = preorder[1];
        int leftRootIndex = 0;
        while (postorder[leftRootIndex] != leftRootValue)
            leftRootIndex++;

        std::vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + leftRootIndex + 2);
        std::vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftRootIndex + 1);
        std::vector<int> rightPreorder(preorder.begin() + leftRootIndex + 2, preorder.end());
        std::vector<int> rightPostorder(postorder.begin() + leftRootIndex + 1, postorder.end() - 1);

        root->left = constructFromPrePost(leftPreorder, leftPostorder);
        root->right = constructFromPrePost(rightPreorder, rightPostorder);

        return root;
    }
};
