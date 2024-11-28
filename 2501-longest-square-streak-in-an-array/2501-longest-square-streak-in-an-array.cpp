class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<int>s;
        for(auto it:nums){
            s.insert(it);
        }
        int ans=-1;
        for(int it:s ){
            int k=1;
            long long int num=static_cast<long long>(it)*it;
            while(s.find(num)!=s.end() && num <= LLONG_MAX / num){
                k++;
                s.erase(num);
                num=num*num;
                
            }
            if(k>=2)ans=max(ans,k);
        }
        return ans;
        
    }
};