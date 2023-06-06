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
    vector<string> binaryTreePaths(TreeNode* root) {
        
        if(root==NULL)return {""};
        
        
        queue<pair<TreeNode*,string>>q;
            
        string k="";
        k+=to_string(root->val);
        vector<string>res;
        q.push({root,k});
        while(q.size()){
            TreeNode*node=q.front().first;
            string p=q.front().second;q.pop();
            if(node->left==nullptr&&node->right==nullptr){
                res.push_back(p);
            }else{
                if(node->left){
                    string l=p+"->" + to_string(node->left->val);
                        
                    q.push({node->left,l});
                }
                if(node->right){
                    string l=p+"->" + to_string(node->right->val);
                       
                    q.push({node->right,l});
                }
            }
        }
        return res;
    }
};