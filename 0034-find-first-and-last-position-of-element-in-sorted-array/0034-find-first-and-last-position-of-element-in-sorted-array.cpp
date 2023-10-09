class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
                while(nums[l]!=target){
                    l++;
                }
                while(nums[h]!=target){
                    h--;
                }
                return {l,h};
            }else if(nums[mid]>target){
                h=mid-1;
                
            }else{
                l=mid+1;
            }
                
        }
        return {-1,-1};
    }
};