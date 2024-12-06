class Solution {
public:
    
    int help(int n,int m,set<int>&banned,vector<vector<int>>&v){
        if(m<0)return -1;
        if(n<1)return 0;
        if(v[n][m]!=-1)return v[n][m];
        int take=0;
        if(banned.find(n)==banned.end()){
            take=1+help(n-1,m-n,banned,v);
           
        }
         int ntake=help(n-1,m,banned,v);
        return v[n][m]= max(take,ntake);
    }
    int maxCount(vector<int>& banned, int n, int maxSum) {
//         long long int sum=0;
//         set<int>s;int cnt=0;
//         for(auto it:banned)s.insert(it);
        
//         for(int i=1;i<=n;i++){
//             if(s.find(i)==s.end()){
//                 if(sum+i<maxSum){
//                     sum+=i;
//                     cnt++;
//                 }
//             }
//         }
        
        // return cnt;
//         vector<vector<int>>dp(n+1,vector<int>(maxSum+1,-1));
//         return help(min(n,maxSum),maxSum,s,dp);
        
        unordered_set<int> bannedSet(banned.begin(), banned.end());
        
        long long sum = 0; // Track cumulative sum
        int count = 0;     // Track count of valid numbers

        // Iterate through 1 to n
        for (int i = 1; i <= n; i++) {
            if (bannedSet.count(i)) continue; // Skip banned numbers
            sum += i; // Add current number to the sum
            if (sum > maxSum) break; // Stop if sum exceeds maxSum
            count++; // Increment count of valid numbers
        }

        return count; 
        
        
        
        
    }
};