//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int help(int x, int y, string s1, string s2,vector<vector<int>>&dp){
        if(x==0||y==0){
            if(s1[x]==s2[y])return 1;
            else if(x>0){
                return help(x-1,y,s1,s2,dp);
                
            }else if(y>0){
                return help(x,y-1,s1,s2,dp);
            }else {
                return 0;
            }
        }
        if(dp[x][y]!=-1)return dp[x][y];
        int k=0;
        if(s1[x]==s2[y])k=1+help(x-1,y-1,s1,s2,dp);
        else{
            int l=0,r=0;
            if(x!=0)
            l=help(x-1,y,s1,s2,dp);
            if(y!=0)
            r=help(x,y-1,s1,s2,dp);
            k= max(l,r);
        }
        return dp[x][y]=k;
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int k=help(m-1,n-1,X,Y,dp);
        // for(int i=1;i<m+1;i++){
        //     for(int j=1;j<n+1;j++){
        //         if(X[i-1]==X[j-1]){
        //             dp[i][j]=dp[i-1][j-1]+1;
        //         }else{
        //             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //         }
        //     }
        // }
       
        return X.length()+Y.length()-(k);
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends