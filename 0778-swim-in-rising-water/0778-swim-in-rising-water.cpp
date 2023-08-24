class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int i, int j, int threshold, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] || grid[i][j] > threshold) {
            return false;
        }
        
        visited[i][j] = true;
        
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return true;
        }
        
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            if (dfs(grid, ni, nj, threshold, visited)) {
                return true;
            }
        }
        
        return false;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0, high = n * n - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            
            if (dfs(grid, 0, 0, mid, visited)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};
