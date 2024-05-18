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
    int getBalance(TreeNode *root, int &totalMoves) {
        if(root == NULL) {
            return 0;
        }
        int lBalance = getBalance(root->left, totalMoves);
        int rBalance = getBalance(root->right, totalMoves);
        totalMoves += abs(lBalance) + abs(rBalance);

        int currentBalance = root->val + lBalance + rBalance - 1;
        return currentBalance;
    }

    int distributeCoins(TreeNode* root) {
        int ans = 0;
        getBalance(root, ans);
        return ans;
    }
    
};