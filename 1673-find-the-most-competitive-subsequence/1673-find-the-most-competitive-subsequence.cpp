class Solution {
public:
   
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            while(st.size()&&nums[i]<nums[st.top()]&&st.size()+nums.size()-i>k){
                st.pop();
            }
            if(st.size()<k){
                st.push(i);
            }
        }
       
        vector<int>res;
        while(st.size()){
            res.push_back(nums[st.top()]);st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};