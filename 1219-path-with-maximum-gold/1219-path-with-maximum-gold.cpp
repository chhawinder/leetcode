  int m;
        int n;
        int delx[]={-1,0,1,0};
        int dely[]={0,-1,0,1};
class Solution {
    bool check (int a,int b)
    {
        return (a>=0 && a<n && b>=0 && b<m);
    }
    int dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>>& vis)
    {
        vis[i][j]=1;
        int sum=0;
        for(int k=0;k<4;k++)
        {
            int in=i+delx[k];
            int jn=j+dely[k];
            if(check(in,jn))
            {
                if(vis[in][jn]==0 && grid[in][jn]!=0)
                sum=max(sum,dfs(in,jn,grid,vis));
            }
        }
        vis[i][j]=0;
        return sum+grid[i][j];
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        m=grid[0].size();
         n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    vector<vector<int>> vis(n,vector<int>(m));
                    ans=max(ans,dfs(i,j,grid,vis));
                }
            }
        }
        return ans;
    }
};