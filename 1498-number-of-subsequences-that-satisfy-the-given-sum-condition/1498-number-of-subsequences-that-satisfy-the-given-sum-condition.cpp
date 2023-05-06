class Solution {
public:
    int help(vector<int>& nums, int target,int mn,int mx,int i){
        if(i<0){
            return 0;
        }
        int mn1=min(mn,nums[i]);
        int mx1=max(mx,nums[i]);
        int take=0;
        if(mn1+mx1<=target){
            take=1+help(nums,target,mn1,mx1,i-1);
        }
        int ktake=help(nums,target,mn1,mx1,i-1);
        int ntake=help(nums,target,mn,mx,i-1);
        return take+ntake+ktake;
    }
    int numSubseq(vector<int>& nums, int target) {
       //return help(nums,target,1e9,-1e9,nums.size()-1);
        int count=0,n=nums.size(),l=0,r=n-1,mod=1e9+7;
        sort(nums.begin(),nums.end());
        vector<int>pow(n,1);
        for(int i=1;i<n;i++){
            pow[i]=pow[i-1]*2%mod;
        }
        while(l<=r){
            if(nums[l]+nums[r]>target){
                r--;
            }else{
                count+=pow[r-l++];
                    count%=mod;
            }
        }
        
        
        
        
        
        return count;
        
        
        
    }
};