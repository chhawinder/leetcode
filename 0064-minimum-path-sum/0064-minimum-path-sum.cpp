class Solution {
public:
//     int help(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
//         int n=grid.size();
//         int m=grid[0].size();
//         if(i>=n||j>=m)return 10000000;
//             if (i == n - 1 && j == m - 1) return grid[i][j];
        
//         if(dp[i][j]!=-1)return dp[i][j];
//         int r=grid[i][j]+min(help(grid,i+1,j,dp),help(grid,i,j+1,dp));
//         return dp[i][j]=r;
        
//     }
    
    int help(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){
        if(i<0||j<0)return 1e9;
        if(i==0&&j==0)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]= min(help(grid,i-1,j,dp),help(grid,i,j-1,dp))+grid[i][j];
    }
   
    int minPathSum(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        // return help(grid,0,0,dp);
        
        return help(grid,n-1,m-1,dp);
    }
};