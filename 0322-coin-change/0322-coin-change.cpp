class Solution {
public:
    int help(vector<int>& c, int n, int t,vector<vector<int>>&dp){
	    if(t==0){
	        return 0;
	    }
	    if(n==0){
	        if(t%c[n]==0)return t/c[n];
	        else return 1000000;
	    }
	    if(dp[n][t]!=-1)return dp[n][t];
	    
	    int ntake =0+help(c,n-1,t,dp);
	    int take=1000000;
	    if(c[n]<=t){
	        take=1+help(c,n,t-c[n],dp);
	    }
	    return  dp[n][t]=min(take,ntake);
	}
    int coinChange(vector<int>& coins, int target) {
        int M=coins.size();
        vector<vector<int>>dp(M,vector<int>(target+1,-1));
	   if(help(coins,M-1,target,dp)==1000000) return -1;
	   else return help(coins,M-1,target,dp);
	    
        
    }
};