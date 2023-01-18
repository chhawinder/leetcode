class Solution {
public:
    long long int help(vector<int>& c,int n,int sum,vector<vector<int>>&dp){
      if(n==0){
          if(sum%c[n]==0)return 1;
          else return 0;
      }
      
      if(sum==0){
          return 1;
      }
      if(dp[n][sum]!=-1)return dp[n][sum];
       int take=0;
      if(sum>=c[n])
       take =help(c,n,sum-c[n],dp);
       int ntake=help(c,n-1,sum,dp);
      return dp[n][sum]=take+ntake;
  }
    int change(int sum, vector<int>& coins) {
        int N=coins.size();
        vector<vector< int>>dp(N,vector< int>(sum+1,-1));
       return help(coins,N-1,sum,dp);
    }
};