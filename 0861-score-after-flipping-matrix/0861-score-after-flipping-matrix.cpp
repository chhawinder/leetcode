class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        // making first column all 1's

        // The first step in the approach is to make the first column all 1's by flipping 
        // the rows if the first element in the row is 0. This ensures that the first 
        // column contributes the maximum possible value to the final score.


        for (int i = 0; i < rows; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == 0)
                           grid[i][j] = 1;
                    else
                        grid[i][j] = 0;
                }
            }
        }
        // flip the columns where noz>noo

        // Next, we iterate through each column and count the number of 0's and 1's 
        // in that column. If the number of 0's is greater than the number of 1's, we flip
        //  that column by changing all 0's to 1's and vice versa. This step ensures that 
        //  each column  contributes the maximum possible value to the final score.
        for (int j = 0; j < cols; j++) {
            int noz = 0;
            int noo = 0;
            for (int i = 0; i < rows; i++) {
                if (grid[i][j] == 0)
                    noz++;
                else
                    noo++;
            }
            if (noz > noo) {
                for (int i = 0; i < rows; i++) {
                    if (grid[i][j] == 0)
                        grid[i][j] = 1;
                    else
                        grid[i][j] = 0;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            int x = 1;
            for (int j = cols - 1; j >= 0; j--) {
                sum += grid[i][j] * x;
                x *= 2;
            }
        }
        return sum;
    }
};