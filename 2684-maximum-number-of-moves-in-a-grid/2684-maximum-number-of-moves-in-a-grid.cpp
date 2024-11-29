class Solution {
public:
    int help(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
        int n=grid.size(),m=grid[0].size();
        //base condition
        if(i>=n||j>=m||i<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        // now check for the path
        int ans=0;
        if((!(i-1>=n||j+1>=m||i-1<0))&&grid[i-1][j+1]>grid[i][j]){
            ans=max(ans,help(grid,i-1,j+1,dp));
        }
        if((!(i>=n||j+1>=m||i<0))&&grid[i][j+1]>grid[i][j]){
            ans=max(ans,help(grid,i,j+1,dp));
        }
        if((!(i+1>=n||j+1>=m||i+1<0))&&grid[i+1][j+1]>grid[i][j]){
            ans=max(ans,help(grid,i+1,j+1,dp));
        }
        
        return dp[i][j]=ans+1;
        
        
    }
    int maxMoves(vector<vector<int>>& grid) {
        int ans=0;
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++){
            ans=max(ans,help(grid,i,0,dp));
        }
        return ans-1;
        
    }
};