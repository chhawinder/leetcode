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
   vector<TreeNode*> buildTree(int s,int e){
       vector<TreeNode*>ans;
       if(s>e){
           ans.push_back(NULL);
           return ans;
       }
       for(int i=s;i<=e;i++){
           vector<TreeNode*>left=buildTree(s,i-1);
           vector<TreeNode*>right=buildTree(i+1,e);
           for(int j=0;j<left.size();j++){
           for(int k=0;k<right.size();k++){
               TreeNode* root=new TreeNode(i);
               root->left=left[j];
               root->right=right[k];
               ans.push_back(root);
           }
       }
       }
       return ans;
       
   }
    vector<TreeNode*> generateTrees(int n) {
        return buildTree(1,n);
    }
};