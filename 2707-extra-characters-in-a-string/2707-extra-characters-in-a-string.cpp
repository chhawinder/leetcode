class Solution {
public:
int minExtraCharMemo(std::string s, std::vector<std::string>& dictionary, std::unordered_map<std::string, int>& memo) {
    if (memo.count(s) > 0) {
        return memo[s]; // If the result for the current state is already computed, return it from the memo
    }

    std::unordered_set<std::string> dict;
    for (const std::string& word : dictionary) {
        dict.insert(word);
    }

    int n = s.length();
    std::vector<int> dp(n + 1);

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;

        for (int j = i - 1; j >= 0; j--) {
            std::string substring = s.substr(j, i - j);
            if (dict.count(substring)) {
                dp[i] = std::min(dp[i], dp[j]);
            }
        }
    }

    memo[s] = dp[n]; // Memoize the result for the current state
    return dp[n];
}

int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
    std::unordered_map<std::string, int> memo;
    return minExtraCharMemo(s, dictionary, memo);
}
};