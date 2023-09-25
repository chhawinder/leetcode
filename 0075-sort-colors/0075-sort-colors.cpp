class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s=0,i=0,e=nums.size()-1;
        while(i<=e){
            if(nums[i]==2){
                swap(nums[i],nums[e]);
                e--;
            }
            else if(nums[i]==1){
                i++;
            }else{
                swap(nums[i],nums[s]);
                i++;s++;
            }
        }
    }
};