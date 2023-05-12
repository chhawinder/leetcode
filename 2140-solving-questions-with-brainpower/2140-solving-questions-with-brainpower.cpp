class Solution {
public:
    long long memoization(int index,vector<vector<int>>& questions,vector<long>&dp){
        if (index >= questions.size()){ 
            return 0;
        }
        if (dp[index] > 0){
            return dp[index];
        }
        int points = questions[index][0];
        int jump = questions[index][1];
        long skip = memoization(index + 1, questions, dp);
        long solve = points + memoization(index  + 1 + jump, questions, dp);
        dp[index] =max(skip, solve);
        return dp[index];
        
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long>dp(n,-1);
        return memoization(0,questions,dp);
    }
};