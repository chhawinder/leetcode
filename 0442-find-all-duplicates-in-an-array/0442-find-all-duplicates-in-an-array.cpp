class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=1;
        set<int>s;
        for(int i=0;i<nums.size();i++){
            if(count>nums[i]){
                s.insert(nums[i]);
            }else if(count==nums[i]){
                count++;
            }else{
                count=nums[i]+1;
            }
        }
        vector<int>sol;
        for(auto it:s){
            sol.push_back(it);
        }
        return sol;
        
    }
};