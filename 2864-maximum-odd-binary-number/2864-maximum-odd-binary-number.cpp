class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones=0,zeros=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')ones++;
            else zeros++;
        }
        string k="";
        ones--;
        while(ones--){
            k+="1";
        }
        while(zeros--){
            k+="0";
        }
        k+="1";
        return k;
        
    }
};