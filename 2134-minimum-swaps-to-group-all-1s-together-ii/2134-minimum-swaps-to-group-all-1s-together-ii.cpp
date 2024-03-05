class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int one=0;
        for(int i=0;i<nums.size();i++){
            one+=nums[i];
        }
        int i=0,j=one-1;
        int c=0;
        for(int i=0;i<j+1;i++){
            c+=nums[i];
        }
        int res=one-c;
        
        while(i<nums.size()){
            
            if(nums[i]==1)c--;
            if(nums[(j+1)%nums.size()]==1)c++;
            i++;j=(j+1)%nums.size();
            res=min(res,one-c);
        }
        return res;
        
        
    }
};