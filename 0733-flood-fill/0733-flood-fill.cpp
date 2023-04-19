class Solution {
    bool isValid(int nrow, int ncol, int N,int m) {
        return nrow >= 0 && nrow < N && ncol >= 0 && ncol < m;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(q.size()!=0){
            int r=q.front().first;
            int c=q.front().second;
            vis[r][c]=1;
            q.pop();
            int dr[]={0,-1,0,1};
            int dc[]={-1,0,1,0};
            for(int i=0;i<4;i++){
                int nr=dr[i]+r;
                int nc=dc[i]+c;
                if(isValid(nr,nc,image.size(),image[0].size())&&vis[nr][nc]==0&&image[nr][nc]==image[r][c]){
                    q.push({nr,nc});
                    
                }
                
            }
            image[r][c]=color;
            
        }
        return image;
    }
};