class Solution {
public:
    void dfs(vector<vector<char>>& image, int sr, int sc,vector<vector<int>>&vis){
        vis[sr][sc]=1;
     
        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};
        for(int i=0;i<4;i++){
            int nr=sr+dx[i];
            int nc=sc+dy[i];
            if(nr<0||nc<0||nr>=image.size()||nc>=image[0].size())continue;
            if(vis[nr][nc]==0&&image[nr][nc]=='O')dfs(image,nr,nc,vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'&&vis[i][0]==0)dfs(board,i,0,vis);
            if(board[i][m-1]=='O'&&vis[i][m-1]==0)dfs(board,i,m-1,vis);
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'&&vis[0][i]==0)dfs(board,0,i,vis);
            if(board[n-1][i]=='O'&&vis[n-1][i]==0)dfs(board,n-1,i,vis);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0)board[i][j]='X';
            }
        }
        
    }
};