class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<vector<int>>sol;
        while(true){
            vector<int>temp;
            for(auto it:m){
                if(it.second>0){
                    temp.push_back(it.first);
                    m[it.first]--;
                }
            }
            if(temp.size()==0)break;
            sol.push_back(temp);
            
        }
        return sol;
        
    }
};