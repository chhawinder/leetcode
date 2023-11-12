class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sol=0;int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)count++;
            else{
                sol=max(sol,count);
                count=0;
            }
        }
        sol=max(sol,count);
        return sol;
    }
};