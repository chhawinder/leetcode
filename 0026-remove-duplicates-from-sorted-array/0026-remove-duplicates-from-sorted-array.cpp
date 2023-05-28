class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            res.push_back(nums[i]);
            while(i!=n-1&&nums[i]==nums[i+1])i++;
        }
        nums=res;
        return res.size();
    }
};