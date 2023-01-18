//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int help(int price[],int n,int s,int N,vector<vector<int>>&dp){
      if(s==0)return 0;
      if(n==N-1)return price[s-1];
      if(dp[n][s]!=-1)return dp[n][s];
      int ntake=help(price,n+1,s,N,dp);
      int take=0;
      if(s>n)take=price[n]+help(price,n,s-n-1,N,dp);
      return dp[n][s]=max(ntake,take);
      
  }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return help(price,0,n,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends