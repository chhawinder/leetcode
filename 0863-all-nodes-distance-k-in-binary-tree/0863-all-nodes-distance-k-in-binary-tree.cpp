/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>p;
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()!=0){
            TreeNode*curr=q.front();q.pop();
            if(curr->left){
                q.push(curr->left);
                p[curr->left]=curr;
            }
            if(curr->right){
                q.push(curr->right);
                p[curr->right]=curr;
            }
        }
        q.push(target);
        vis[target]=true;
        int level=0;
        while(q.size()){
            int n=q.size();
            if(level++==k)break;
            for(int i=0;i<n;i++){
                TreeNode*curr=q.front();q.pop();
               if(curr->left && !vis[curr->left]) {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right]) {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(p[curr]&&vis[p[curr]]==false){
                    q.push(p[curr]);
                    vis[p[curr]]=true;
                }
            }
        }
        vector<int>res;
        while(q.size()){
            res.push_back(q.front()->val);q.pop();
        }
        return res;
        
    }
};