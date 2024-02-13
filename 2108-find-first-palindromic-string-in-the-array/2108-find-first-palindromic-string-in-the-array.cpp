class Solution {
public:
    bool ispal(string s){
        string st=s;
        reverse(st.begin(),st.end());
        return s==st;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(ispal(words[i]))return words[i];
        }
        return "";
    }
};