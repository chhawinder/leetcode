class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==1){
            return {0,1};
        }
        vector<int>res=grayCode(n-1);
        vector<int>fres;
        for(int i=0;i<res.size();i++){
            fres.push_back(res[i]);
            
        }
        for(int i=res.size()-1;i>=0;i--){
            fres.push_back(res[i]+pow(2,n-1));
        }
        return fres;
        
    }
};