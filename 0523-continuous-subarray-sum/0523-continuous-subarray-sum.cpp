class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //n2-> all subarray
        
        unordered_map<int,int>mpp;
    mpp[0]=-1;
    int sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
       sum+=nums[i];
       if(mpp.find(sum%k)==mpp.end()){
        mpp[sum%k]=i;
       }
       else{
        auto it=mpp.find(sum%k);
        if(i-(it->second)>=2) return true;
       }
    }
    return false;
        
    }
};