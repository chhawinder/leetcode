class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end());
    vector<vector<int>> res;
    
    for (int i = 0; i < inter.size(); i++) {
        int s = inter[i][0];
        int cmp = inter[i][1];
        while (i < inter.size() - 1 && cmp >= inter[i + 1][0]) {
            cmp = max(cmp, inter[i + 1][1]);
            i++;
        }
        res.push_back({s, cmp});
    }
    return res;
    }
};