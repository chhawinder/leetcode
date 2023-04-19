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
    int maxstep=0;
    void dfs(TreeNode* root,bool l,int step){
        if(root==NULL)return;
        maxstep=max(maxstep,step);
        if(l){
            dfs(root->left,false,step+1);
            dfs(root->right,true,1);
        }else{
            dfs(root->right,true,step+1);
            dfs(root->left,false,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root,true,0);
        dfs(root,false,0);
        return maxstep;
    }
};