class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>k;
        int count=0;
        for(auto it:nums){
            if(it!=0){
                k.push_back(it);
            }else{
                count++;
            }
        }
        while(count--){
            k.push_back(0);
        }
        nums=k;
    }
};