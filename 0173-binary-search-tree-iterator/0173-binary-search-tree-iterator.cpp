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
class BSTIterator {
public:
    vector<int>ino;
    int i=0;
    void inor(TreeNode* root){
        if(root==nullptr)return;
        inor(root->left);
        ino.push_back(root->val);
        inor(root->right);
    }
    BSTIterator(TreeNode* root) {
        inor(root);
    }
    
    int next() {
        int k=-1;
        if(i<ino.size()){
            k=ino[i];
        i++;
        }
        
        return k;
    }
    
    bool hasNext() {
        if(i==ino.size())return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */