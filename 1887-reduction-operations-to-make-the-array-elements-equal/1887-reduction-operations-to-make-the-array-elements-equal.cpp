class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        auto it =m.rbegin();
        int sol=0;
        while(it!=m.rend()){
            int temp=it->second;
            // cout<<temp<<" ";
            
            it++;
            if(it==m.rend())break;
            sol+=temp;
            it->second+=temp;
            
        }
        return sol;
        
    }
};