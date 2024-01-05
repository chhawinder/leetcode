class Solution {
private:
    int findLIS(vector<int>& nums, int prevIdx, int currIdx, vector<vector<int>>& dp) {
        if (currIdx == nums.size()) {
            return 0;
        }
        if (dp[prevIdx + 1][currIdx] != -1) {
            return dp[prevIdx + 1][currIdx];
        }
        int length = 0;
        if (prevIdx == -1 || nums[prevIdx] < nums[currIdx]) {
            length = max(1 + findLIS(nums, currIdx, currIdx + 1, dp), findLIS(nums, prevIdx, currIdx + 1, dp));
        }
        else {
            length = findLIS(nums, prevIdx, currIdx + 1, dp);
        }
        return dp[prevIdx + 1][currIdx] = length;
    }

public:
    int lengthOfLIS(vector<int>& arr) {
        // dp[i][j] stores the length of the longest increasing subsequence ending at index j, where the previous element is at index i
        int n=arr.size();
          vector<int>dp(n,1);
    for(int i=0;i<n;i++){
        for(int pre=0;pre<i;pre++){
                if(arr[pre]<arr[i]){
                    dp[i]=max(dp[i],1+dp[pre]);
                }
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        res=max(res,dp[i]);
    }
    return res;
    }
};
