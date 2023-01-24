//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int help(string A,string p,int n,int m,vector<vector<int>>&dp){
      if(n==0||m==0){
          if(A[n]==p[m])return 1;
          else if(m>0) return help(A,p,n,m-1,dp);
          else if (n>0) return help(A,p,n-1,m,dp);
          else return 0;
      }
      if(dp[n][m]!=-1)return dp[n][m];
	if(A[n]==p[m]){
		return dp[n][m]=1+help(A,p,n-1,m-1,dp);
	}
	else{
		int one=help(A,p,n-1,m,dp);
		int two=help(A,p,n,m-1,dp);
		return dp[n][m]=max(one,two);
	}
  }
    int longestPalinSubseq(string A) {
        //code here
        vector<vector<int>>dp(A.length(),vector<int>(A.length(),-1));
        string p=A;
        reverse(p.begin(),p.end());
        return help(A,p,A.length()-1,A.length()-1,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends