class Solution {
public:
    int help(vector<int>& nums, int i, vector<int>& dp) {
        // base
        if (i == nums.size()) return 0;

        if (dp[i] != -1) return dp[i];
        
        // Find the last index for the same value as nums[i]
        int j = i;
        while (j < nums.size() && nums[j] == nums[i]) {
            j++;
        }
        
        // Calculate points by taking all occurrences of the current value
        int take = (j - i) * nums[i] + help(nums, j, dp);
        
        // Calculate points by skipping the current value
        int ntake = help(nums, i + 1, dp);

        return dp[i] = max(take, ntake);
    }

    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> points(maxVal + 1, 0);

        // Calculate the total points for each unique number
        for (int num : nums) {
            points[num] += num;
        }

        // Apply the House Robber approach to calculate the maximum points
        int prev1 = 0, prev2 = 0;
        for (int i = 1; i <= maxVal; i++) {
            int temp = prev1;
            prev1 = max(prev2 + points[i], prev1);
            prev2 = temp;
        }

        return prev1;
    }
};
