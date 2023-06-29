class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp;
        dp.push_back(1);
        int i=0,j=0,k=0;
        for(int p=0;p<n-1;p++){
            int two=2*dp[i];
            int three=3*dp[j];
            int five=5*dp[k];
            int m=min(two,min(three,five));
            dp.push_back(m);
            if(two==m)i++;
            if(three==m)j++;
            if(five==m)k++;
            
        }
        return dp[n-1];
    }
};