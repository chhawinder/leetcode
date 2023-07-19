class Solution {
public:
    int help(string s,int i,vector<int>&dp){
        //base case
        
        if(i>s.size())return 0;
        if(i==s.size())return 1;
        if(s[i]=='0')return 0;
        
        if(dp[i]!=-1)return dp[i];
        
        //take
        
        int take=0,ntake=0;
         ntake=help(s,i+1,dp);
        if(i<s.size()-1&&s[i]=='1'||(s[i]=='2'&&s[i+1]<'7'))take=help(s,i+2,dp);
        //ntake next
       
        return dp[i]=take+ntake;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size()+1,-1);
        return help(s,0,dp);
    }
};