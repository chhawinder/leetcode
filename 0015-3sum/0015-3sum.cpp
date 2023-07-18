class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<vector<int>>res;
        for(int i=0;i<nums.size()-2;i++){
            
            while(i>0&&nums[i]==nums[i-1]&&i<nums.size()-2)i++;
            
            
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    res.push_back({nums[i],nums[j],nums[k]});
                    while(j<nums.size()-1&&nums[j]==nums[j+1])j++;
                    while(k>0&&nums[k]==nums[k-1])k--;
                    j++;k--;
                }else if(sum>0)k--;
                else j++;
            }
        }
        return res;
    }
};