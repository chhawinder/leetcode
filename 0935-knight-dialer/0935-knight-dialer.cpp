class Solution {
public:
    int mod=1e9+7;
    int dfs(vector<vector<int>>&dail,int i,int j,int n,vector<vector<vector<int>>>&dp){
        if(n==1)return 1;
       
        if(dp[i][j][n]!=-1)return dp[i][j][n];
        int dx[]={1,1,-1,-1,2,2,-2,-2};
        int dy[]={2,-2,2,-2,1,-1,1,-1};
        int sol=0;
        for(int k=0;k<8;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];
            if(nr<0||nc<0||nr>=dail.size()||nc>=dail[0].size()||dail[nr][nc]==-1)continue;
            sol=(sol+dfs(dail,nr,nc,n-1,dp))%mod;
        }
        return dp[i][j][n]=sol;
    }
    int knightDialer(int n) {
        vector<vector<int>>dail={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        vector<vector<vector<int>>>dp(dail.size(),vector<vector<int>>(dail[0].size(),vector<int>(n+1,-1)));
        int ans=0;
        for(int i=0;i<dail.size();i++){
            for(int j=0;j<dail[0].size();j++){
                if(dail[i][j]!=-1){
                    ans= (ans+dfs(dail,i,j,n,dp))%mod;
                }
            }
        }
        return ans;
        
    }
};