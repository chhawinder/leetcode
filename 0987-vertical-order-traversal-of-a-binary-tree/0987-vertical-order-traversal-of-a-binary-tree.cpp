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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        map<int,vector<pair<int,int>>>m;
        while(q.size()){
            int n=q.size();
            for(int i=0;i<n;i++){
                 TreeNode*temp=q.front().first;
            int l=q.front().second.first;
            int w=q.front().second.second;q.pop();
                m[w].push_back({l,temp->val});
                if(temp->right){
                    q.push({temp->right,{l+1,w+1}});
                }
                if(temp->left){
                    q.push({temp->left,{l+1,w-1}});
                }
                
            }
           
        }
        vector<vector<int>>res;
        for(auto it:m){
            sort(it.second.begin(),it.second.end());
            vector<int>temp;
            for(auto it1:it.second){
                temp.push_back(it1.second);
            }
            res.push_back(temp);
        }
        return res;
    }
};