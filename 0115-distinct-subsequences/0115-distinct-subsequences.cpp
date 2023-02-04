class Solution {
public:
    
int help(string &t,string &s,int n,int m,vector<vector<int>>&dp){
    if(m<0)return 1;
    if(n<0)return 0;
    if(dp[n][m]!=-1)return dp[n][m];
    int ntake= help(t,s,n-1,m,dp);
    int take=0;
    if(t[n]==s[m])take=help(t,s,n-1,m-1,dp);
    return dp[n][m]=take+ntake;
}
    int numDistinct(string s, string t) {
        int lt=s.length(),ls=t.length();
        vector<vector<int>>dp(lt+1,vector<int>(ls+1,-1));
    return help(s,t,lt-1,ls-1,dp);
        
    }
};