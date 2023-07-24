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
    void maping(TreeNode* root,map<TreeNode*,TreeNode*>&m,TreeNode*par){
        if(root==nullptr)return;
        if(par!=nullptr){
            m[root]=par;
        }
        maping(root->left,m,root);
        maping(root->right,m,root);
        return ;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>m;
        maping(root,m,nullptr);
        queue<TreeNode*>q;
        q.push(target);
        set<TreeNode*>vis;
        while(k--){
            int n=q.size();
            while(n--){
                TreeNode*temp=q.front();q.pop();
                vis.insert(temp);
                if(temp->left&&vis.find(temp->left)==vis.end())q.push(temp->left);
                if(temp->right&&vis.find(temp->right)==vis.end())q.push(temp->right);
                if(m[temp]&&vis.find(m[temp])==vis.end())q.push(m[temp]);

                
            }
            
        }
        vector<int>res;
        while(q.size()){
            TreeNode*temp=q.front();q.pop();res.push_back(temp->val);
        }
        return res;
    }
};