class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1,zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i])
            prod*=nums[i];
            else
                zero++;
            
        }
        vector<int>res(nums.size(),0);
        if(zero>1)return res;
        
        if(zero==1){
            
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0)res[i]=prod;
            }
            return res;
        }
        
        for(int i=0;i<nums.size();i++){
            res[i]=prod/nums[i];
        }
        return res;
        
    }
};