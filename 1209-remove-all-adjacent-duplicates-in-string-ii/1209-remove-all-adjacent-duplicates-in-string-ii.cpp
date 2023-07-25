class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++){
            if(!st.size()||st.top().first!=s[i]){
                st.push({s[i],1});
            }else{
                if(st.top().second+1==k)st.pop();
                else{
                    int p=st.top().second;
                    st.pop();
                    st.push({s[i],p+1});
                }
            }
        }
        string sol="";
        while(st.size()){
            char c=st.top().first;
            int m=st.top().second;st.pop();
            while(m--)sol+=c;
        }
        reverse(sol.begin(),sol.end());
        return sol;
    }
};