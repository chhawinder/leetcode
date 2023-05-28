class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc,vector<vector<int>>&vis, int color,int ini){
        vis[sr][sc]=1;
        image[sr][sc]=color;
        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};
        for(int i=0;i<4;i++){
            int nr=sr+dx[i];
            int nc=sc+dy[i];
            if(nr<0||nc<0||nr>=image.size()||nc>=image[0].size())continue;
            if(vis[nr][nc]==0&&image[nr][nc]==ini)dfs(image,nr,nc,vis,color,ini);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
        int ini=image[sr][sc];
        dfs(image,sr,sc,vis,color,ini);
        return image;
    }
};