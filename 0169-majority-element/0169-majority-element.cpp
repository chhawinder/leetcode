class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0,res;
        for(int i=0;i<nums.size()-1;i++){
            while(i!=nums.size()-1&&nums[i]==nums[i+1]){
                count++;res=nums[i];i++;
            }
            if(count>=(nums.size()/2))return res;
            count=0;
        }
        return nums[0];
    }
};