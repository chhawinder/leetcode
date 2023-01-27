class Solution {
public:
    int minInsertions(string str) {
        int n1=str.size();
    int n2=n1;
    string str2=str;
        reverse(str2.begin(),str2.end());
        vector<vector<int>>dp(n1+1,vector<int>(n2+1));
        int k=0;
        for(int i=1;i<n1+1;i++){
            for(int j=1;j<n2+1;j++){
                if(str[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                   
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                 k=max(k,dp[i][j]);
            }
        }
      
        return n1-k;
        
    }
};