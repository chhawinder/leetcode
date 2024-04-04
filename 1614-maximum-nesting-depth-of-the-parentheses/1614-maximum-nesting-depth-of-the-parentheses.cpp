class Solution {
public:
    int maxDepth(string s) {
        int res=0;
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push('(');
            else if(s[i]==')')st.pop();
            res=max((int)st.size(),res);
        }
        return res;
        
    }
};