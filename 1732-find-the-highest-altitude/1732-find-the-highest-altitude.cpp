class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0,res=0;
        for(auto it:gain){
            res=max(res,sum);
            cout<<res<<" ";
            sum+=it;
        }
       res=max(res,sum);             

        return res;
    }
};