class Solution {
public:
    void justgreter(vector<int>& nums,int s){
        int comp=nums[s];
        int sw=s+1;
        for(int i=s+2;i<nums.size();i++){
            if(nums[i]>comp){
                if(nums[i]<nums[sw]){
                    sw=i;
                }
            }
        }
        swap(nums[s],nums[sw]);
    }
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                 justgreter(nums,i-1);
                sort(nums.begin()+i,nums.end());
                
                return;
            }
        }
        reverse(nums.begin(),nums.end());
        
    }
};