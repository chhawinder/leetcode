class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", n, n);
        return ans;
    }

    void backtrack(vector<string>& ans, string current, int open, int close) {
        if (open == 0 && close == 0) {
            ans.push_back(current);
            return;
        }

        if (open > 0) {
            backtrack(ans, current + '(', open - 1, close);
        }

        if (close > open) {
            backtrack(ans, current + ')', open, close - 1);
        }
    }
};
