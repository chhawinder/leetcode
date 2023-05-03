class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans;
        unordered_map<int,int>m1,m2;
        for(int i=0;i<nums1.size();i++){
            m1[nums1[i]]++;
           
        }
        for(int i=0;i<nums2.size();i++){
             m2[nums2[i]]++;
        }
        vector<int>k;
        for(auto it:m1){
            if(m2.find(it.first)==m2.end()){
                k.push_back(it.first);
            }
        }
        vector<int>k2;
        for(auto it:m2){
            if(m1.find(it.first)==m1.end()){
                k2.push_back(it.first);
            }
        }
        ans.push_back(k);
        ans.push_back(k2);
        return ans;
        
    }
};