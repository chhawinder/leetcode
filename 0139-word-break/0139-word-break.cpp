class Solution {
public:
    bool help(string s, set<string>& dict, int i, vector<int>& dp){
        if(i==s.size()){
          
            return true;
        }
        if(dp[i]!=-1)return dp[i];
        for (int j = i + 1; j <= s.size(); j++) {
            string word = s.substr(i, j - i);
            if (dict.find(word) != dict.end() && help(s, dict, j, dp)) {
                return dp[i] = true;
            }
        }
        
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>dict;
        for(int i=0;i<wordDict.size();i++){
            dict.insert(wordDict[i]);
        }
        vector<int>dp(s.size(),-1);
        return help(s,dict,0,dp);
    }
};