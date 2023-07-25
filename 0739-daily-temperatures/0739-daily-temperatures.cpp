class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmp) {
        vector<int>res(tmp.size(),0);
        stack<int>st;
        for(int i=0;i<tmp.size();i++){
            if(!st.size()||tmp[st.top()]>tmp[i]){
                st.push(i);
            }else{
                while(st.size()&&tmp[st.top()]<tmp[i]){
                    int k=st.top();st.pop();
                    res[k]=i-k;
                }
                st.push(i);
            }
        }
        return res;
    }
};