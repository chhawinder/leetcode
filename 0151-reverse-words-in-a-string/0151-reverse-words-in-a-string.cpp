class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string k="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                k+=s[i];
            }else{
                st.push(k);
                k="";
            }
        }
        st.push(k);
        string res="";
        while(st.size()){
            if(st.top().size()){
                  res+=st.top();
            
            res+=" ";
            }
            st.pop();
          
        }
        res.pop_back();
        return res;
    }
};