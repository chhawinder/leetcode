class Solution {
public:
    bool checkpal(string k){
        string t=k;
        reverse(t.begin(),t.end());
        return t==k?true:false;
    }
    void help(string s,vector<string>&res,vector<vector<string>>&ans){
        if(s.size()==0){
            ans.push_back(res);
            return;
        }
       
        for(int i=1;i<=s.size();i++){
            string k=s.substr(0,i);
            if(checkpal(k)){
                res.push_back(k);
                help(s.substr(i),res,ans);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>res;
        vector<vector<string>>ans;
        help(s,res,ans);
        return ans;
    }
};