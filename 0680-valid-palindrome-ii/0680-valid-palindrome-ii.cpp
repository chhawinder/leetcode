class Solution {
public:
    
    bool validPalindrome(string s) {
        return help(s,0,s.size()-1,0);
    }
    bool help(string s,int low,int high,int count){
        if(count>1)return false;
        while(low<high){
            if(s[low]==s[high]){
                low++;high--;
            }else{
                return help(s,low+1,high,count+1)||help(s,low,high-1,count+1);
            }
        }
        return true;
    }
};