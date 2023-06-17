class Solution {
public:
    void help(int i,vector<int>& num,set<vector<int>>&ans){
        if(i==num.size()){
            ans.insert(num);
            return ;
        }
        for(int j=i;j<num.size();j++){
            swap(num[j],num[i]);
            help(i+1,num,ans);
            swap(num[j],num[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>ans;
        help(0,nums,ans);
        vector<vector<int>>ans1;
        for(auto it:ans){
            ans1.push_back(it);
        }
        return ans1;
    }
};