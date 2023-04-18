class Solution {
public:
    int help(vector<vector<int>>& triangle,int i,int j,int n,vector<vector<int>>&dp){
        if(i==n-1)return triangle[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j] =min(help(triangle,i+1,j+1,n,dp),help(triangle,i+1,j,n,dp))+triangle[i][j];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
          vector<vector<int> > dp(n,vector<int>(n,-1));
        return help(triangle,0,0,n,dp);
    }
};