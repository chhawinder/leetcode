//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
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
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>>dp(x,vector<int>(y,-1));
        return help(x-1,y-1,s1,s2,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends