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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int temp;
        while(q.size()){
            int n=q.size();
            temp=q.front()->val;
            while(n--){
                TreeNode* temp1=q.front();
                q.pop();
                if(temp1->left)q.push(temp1->left);
                if(temp1->right)q.push(temp1->right);
                
                
            }
        }
        return temp;
    }
};