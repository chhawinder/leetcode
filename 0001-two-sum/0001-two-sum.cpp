class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        // cout<<m[2]<<" ";
        for(int i=0;i<nums.size();i++){
            if(m.find(target-nums[i])!=m.end()&&i!=m[target-nums[i]]){
                return {i,m[target-nums[i]]};
            }
        }
        return {-1,-1};
    }
};