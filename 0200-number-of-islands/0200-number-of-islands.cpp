class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int num=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&vis[i][j]==0){
                    queue<pair<int,int>>q;
                    num++;
                    vis[i][j]=1;
                    q.push({i,j});
                    int dx[]={0,0,-1,1};
                    int dy[]={-1,1,0,0};
                    while(q.size()){
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nr=r+dx[k];
                            int nc=c+dy[k];
                            if(nr<0||nc<0||nr>=n||nc>=m)continue;
                            if(grid[nr][nc]=='1'&&vis[nr][nc]==0){
                                vis[nr][nc]=1;
                                q.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }
        return num;
    }
};