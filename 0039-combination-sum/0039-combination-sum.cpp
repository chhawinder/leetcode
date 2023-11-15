class Solution {
public:
    void help(vector<int> arr, int i,int k,set<vector<int>>&sol,vector<int> sub){
    if(k==0){
        sol.insert(sub);
        
    }
    if(i==arr.size())return ;
    //ntake
    help(arr,i+1,k,sol,sub);
    //take
    if(k>=arr[i]){
        sub.push_back(arr[i]);
        help(arr,i,k-arr[i],sol,sub);
    }
        
    
}
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        set<vector<int>>sol;
    help(arr, 0, k, sol, {});
    vector<vector<int>>res;
    for(auto it:sol){
        res.push_back(it);
    }
    return res;
    }
};