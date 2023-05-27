class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>p;
        for(int i=0;i<nums2.size();i++){
            bool flag=0;
            for(int j=i+1;j<nums2.size();j++){
                if(nums2[j]>nums2[i]){
                    p.push_back(nums2[j]);
                    flag=1;
                    break;
                }
            }
            if(flag==0)p.push_back(-1);
            
        }
        vector<int>res;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    res.push_back(p[j]);
                    break;
                }
            }
        }
        return res;
    }
};