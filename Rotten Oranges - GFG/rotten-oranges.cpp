//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int ct=0;
        queue<pair<pair<int,int>,int>>q;
        int visited[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }else {
                    if(grid[i][j]==1)ct++;
                    visited[i][j]=0;
                }
            }
        }
        int dcol[]={0,-1,0,1};
        int drow[]={1,0,-1,0};
        int tim=0;
        int count=0;
        while(q.size()!=0){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tim=max(tim,t);
            q.pop();
            for(int i=0;i<4;i++){
                int dr=drow[i]+r;
                int dc=dcol[i]+c;
                if(dr<n&&dc<m&&dr>-1&&dc>-1&&grid[dr][dc]==1&&visited[dr][dc]!=2){
                    q.push({{dr,dc},t+1});
                    visited[dr][dc]=2;
                    count++;
                }
            }
            
            
        }
        if(ct!=count)return -1;
        return tim;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends