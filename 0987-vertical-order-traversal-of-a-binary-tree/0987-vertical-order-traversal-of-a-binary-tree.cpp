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
        vector<vector<int>> res;
        map<int, map<int, multiset<int>>> m; // {horizontalDistance: {depth: values}}
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}}); // {TreeNode*, {horizontalDistance, depth}}
        
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int hd = q.front().second.first;
            int depth = q.front().second.second;
            q.pop();
            
            m[hd][depth].insert(node->val);
            
            if (node->left != nullptr)
                q.push({node->left, {hd - 1, depth + 1}});
            
            if (node->right != nullptr)
                q.push({node->right, {hd + 1, depth + 1}});
        }
        
        for (auto& it : m) {
            vector<int> level;
            for (auto& pair : it.second) {
                level.insert(level.end(), pair.second.begin(), pair.second.end());
            }
            res.push_back(level);
        }
        
        return res;
    }
};

