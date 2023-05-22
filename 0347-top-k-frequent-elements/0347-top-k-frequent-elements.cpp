class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<pair<int, int>> vec(mp.begin(), mp.end());

        sort(vec.begin(), vec.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.second > rhs.second; // Sort by frequency in descending order
    });
        vector<int>res;
        for(auto it :vec){
            if(k){
                  res.push_back(it.first);
                  k--;
            }
              
            
        }
        return res;
    }
};