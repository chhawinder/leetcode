class Solution {
public:
    int help(vector<int>& prices,int i,int buy,vector<vector<int>>&dp){
        if(i==prices.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int take;
        if(buy==1){
            take=-prices[i]+help(prices,i+1,0,dp);
        }else{
            take=+prices[i];
        }
        int ntake=help(prices,i+1,buy,dp);
        return dp[i][buy]=max(take,ntake);
            
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return help(prices,0,1,dp);
    }
};