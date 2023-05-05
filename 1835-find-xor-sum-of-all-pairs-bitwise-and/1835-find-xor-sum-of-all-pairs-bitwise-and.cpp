class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int res=0;
        for(auto it1:arr1){
            res=res^it1;
        }
        int res2=0;
        for(auto it2:arr2){
                res2=res2^it2;
        }
        return res&res2;
    }
};