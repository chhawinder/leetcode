class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        int k=nums.size()/3;
        vector<int>sol;
        for(auto it:m){
            if(it.second>k){
                sol.push_back(it.first);
            }
        }
        return sol;
    }
};