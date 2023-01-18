//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	
	int help(int c[], int n, int t,vector<vector<int>>&dp){
	    if(t==0){
	        return 0;
	    }
	    if(n==0){
	        if(t%c[n]==0)return t/c[n];
	        else return 1000000;
	    }
	    if(dp[n][t]!=-1)return dp[n][t];
	    
	    int ntake =0+help(c,n-1,t,dp);
	    int take=1000000;
	    if(c[n]<=t){
	        take=1+help(c,n,t-c[n],dp);
	    }
	    return  dp[n][t]=min(take,ntake);
	}
	int minCoins(int coins[], int M, int target) 
	{ 
	    vector<vector<int>>dp(M,vector<int>(target+1,-1));
	   if(help(coins,M-1,target,dp)==1000000) return -1;
	   else return help(coins,M-1,target,dp);
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    // Your code goes here
	   //  vector<vector<int>>dp(M,vector<int>(target+1,-1));
    //     for(int i=0;i<M;i++)dp[i][0]=0;
    //     for(int i=1;i<target+1;i++)if(i%coins[0]==0)dp[0][i]=i/coins[0];
    //     for(int i=1;i<M;i++){
    //         for(int j=1;j<target+1;j++){
    //             int k=dp[i-1][j%coins[i]];
    //             if(k==-1)dp[i][j]=-1;
    //             else{
    //                  int l=j/coins[j];
    //             dp[i][j]=k+l;
    //             }
               
    //         }
    //     }
    //     return dp[M-1][target];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends