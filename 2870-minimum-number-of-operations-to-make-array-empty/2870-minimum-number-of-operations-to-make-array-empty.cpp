class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int sol=0;
        for(auto it:m){
            if(it.second%3==0){
                sol+=it.second/3;
            }else if(it.second%3==2){
                sol+=it.second/3;sol++;
                    
            }else {
                int k=it.second/3;
                while(k){
                    if((it.second-k*3)%2==0){
                        sol+=k+(it.second-k*3)/2;
                        break;
                    }
                    k--;
                }
                if(k==0&&it.second%2==0){
                    sol+=it.second/2;
                }else if(k==0){
                    return -1;
                }
                
            }
        }
        return sol;
        
    }
};