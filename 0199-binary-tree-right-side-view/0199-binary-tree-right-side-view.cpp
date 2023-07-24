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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>res;
        while(q.size()){
            int n=q.size();
            int k=0;
            while(n--){
                TreeNode*temp=q.front();q.pop();
                k=temp->val;
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            res.push_back(k);
        }
        return res;
    }
};