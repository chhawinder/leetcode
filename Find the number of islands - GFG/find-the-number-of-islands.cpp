//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(vector<vector<char>>& grid,vector<vector<int>>& v,int i,int j){
        queue<pair<int,int>>q;
        int n=grid.size();
        int t=grid[0].size();
        q.push({i,j});
        while(q.size()!=0){
            int k=q.front().first;
             int m=q.front().second;
             
             q.pop();
             if(v[k][m]==0){
                 v[k][m]=1;
                for(int p=-1;p<2;p++){
                    for(int o=-1;o<2;o++){
                        if((k+p>-1&&k+p<n)&&(m+o>-1&&m+o<t)){
                            if(v[k+p][m+o]==0&&grid[k+p][m+o]=='1'){
                              q.push({k+p,m+o});
                            }
                        }
                    }
                }
             }
        }
        return ;
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>v(n,vector<int>(m,0));
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&v[i][j]==0){
                    bfs(grid,v,i,j);
                    res++;
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends