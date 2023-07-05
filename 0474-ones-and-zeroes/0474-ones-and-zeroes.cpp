class Solution {
public:
    int help(vector<string>& strs, int m, int n,int id,vector<vector<vector<int>>>&dp){
        if(id==strs.size())return 0;
        int zero=0,one=0;
        //string k = to_string(m) + "|" + to_string(n) + "|" + to_string(id) + "|" + strs[id];
        if(dp[id][m][n]!=-1)return dp[id][m][n];
        for(int i=0;i<strs[id].size();i++){
            if(strs[id][i]=='0')zero++;
            else one++;
        }
        int take=0,ntake;
        if(zero<=m&&one<=n){
            take=help(strs,m-zero,n-one,id+1,dp)+1;
        }
        ntake=help(strs,m,n,id+1,dp);
        
        return dp[id][m][n]=max(take,ntake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size=strs.size();
        vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return help(strs,m,n,0,dp);
    }
};