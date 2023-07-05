class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        long long int pro=1;int neg=0,zero=0;
        if(nums.size()==0)return 0;
        if(nums.size()==1)return nums[0];
        for(auto it:nums){
            if(it!=0&&zero==0){
                pro*=it;
                if(it<0)neg++;
                
            }else if(it==0){
                zero++;
            }
        }
        if(zero==0){
            if(neg%2==0)return pro;
            else{
                int p1=1;
                int res=1;
                for(auto it:nums){
                    if(it>0){
                        p1*=it;
                    }else{
                        int su=pro/(p1*it);
                        res=max(res,max(su,p1));
                        p1*=it;
                    }
                }
                return res;
            }
        }
      
            vector<int>kp;
            int ans=0;
            for(auto it:nums){
                if(it!=0){
                    kp.push_back(it);
                }else if(it==0&&kp.size()){
                    ans=max(ans,maxProduct(kp));
                    kp.clear();
                }
            }
        if(kp.size())ans=max(ans,maxProduct(kp));
        return ans;
        
    }
};