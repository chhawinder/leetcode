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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if(preorder.size()==0)return NULL;
        TreeNode*root=new TreeNode(preorder[0]);
        vector<int>lpre,lpost;
        int i=1;
        while(i<postorder.size()&&preorder[i]!=postorder[postorder.size()-2]){
           lpost.push_back(postorder[i-1]);
            lpre.push_back(preorder[i++]);
            
        }
        root->left=constructFromPrePost(lpre,lpost);
        vector<int>rpre,rpost;
        while(i<postorder.size()){
            rpost.push_back(postorder[i-1]);
            rpre.push_back(preorder[i++]);
        }
        root->right=constructFromPrePost(rpre,rpost);
        return root;
        
    }
};