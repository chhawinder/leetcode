class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int mx=1;
        map<int,int>m;
        for(auto it:nums)m[it]=1;
        
        for(auto it=m.begin();it!=m.end();it++){
            int temp=it->first;
            while(m.find(it->first+1)!=m.end()){
                m[temp]+=1;
                mx=max(mx,m[temp]);
                it++;
            }
        }
        return mx;
    }
};