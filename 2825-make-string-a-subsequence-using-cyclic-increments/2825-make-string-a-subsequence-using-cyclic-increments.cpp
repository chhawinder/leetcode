class Solution {
public:
    char nextchar(char c){
        if(c=='z')return 'a';
        else return c+1;
    }
    bool canMakeSubsequence(string str1, string str2) {
        
        int i=0,j=0;
        while(i<str1.size()&&j<str2.size()){
            if(str1[i]==str2[j]||nextchar(str1[i])==str2[j]){
                i++;j++;
            }else{
                i++;
            }
        }
        if(j>=str2.size())return true;
        return false;
    }
};