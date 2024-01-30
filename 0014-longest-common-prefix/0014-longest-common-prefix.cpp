class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res=strs[0];
        for(int i=1;i<strs.size();i++){
            int k=0;
            while(k<=min(res.size(),strs[i].size())){
                if(res[k]==strs[i][k])k++;
                else{
                    res=res.substr(0,k);
                    break;
                }
            }
        }
        return res;
        
    }
};