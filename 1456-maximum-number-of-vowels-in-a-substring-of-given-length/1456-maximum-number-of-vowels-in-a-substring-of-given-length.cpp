class Solution {
public:
    int help(string s, int k,int i,vector<vector<int>>&dp){
        if(k<=0)return 0;
        if(i<0)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int ntake=help(s,k,i-1,dp);
        int take=0;
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            take=1+help(s,k-1,i-1,dp);
        }else{
            take=help(s,k-1,i-1,dp);
        }
        return dp[i][k]=max(ntake,take);
        
    }
    int maxVowels(string s, int k) {
         int vowelCount = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                vowelCount++;
            }
        }
        int maxVowelCount = vowelCount;
        for (int i = k; i < s.length(); i++) {
            if (s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u') {
                vowelCount--;
            }
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                vowelCount++;
            }
            maxVowelCount = max(maxVowelCount, vowelCount);
        }
        return maxVowelCount;
    }
};