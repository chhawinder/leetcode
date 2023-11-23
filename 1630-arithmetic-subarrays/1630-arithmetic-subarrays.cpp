class Solution {
public:
    bool arth(vector<int>temp){
        int d=temp[1]-temp[0];
        for(int i=1;i<temp.size()-1;i++){
            if(temp[i+1]-temp[i]!=d)return false;
        }
        return true;
    }
    bool help(vector<int> nums,int l,int r){
        vector<int>temp;
        for(int i=l;i<=r;i++){
            temp.push_back(nums[i]);
        }
        sort(temp.begin(),temp.end());
        if(arth(temp))return true;
        return false;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        for(int i=0;i<l.size();i++){
            bool sol=help(nums,l[i],r[i]);
            ans.push_back(sol);
        }
        return ans;
    }
};