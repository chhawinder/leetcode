//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int n, vector<int> edge)
  {
      // code here
      vector<int>ed(n,0);
      for(int i=0;i<n;i++){
          if(edge[i]!=-1)
          ed[edge[i]]+=i;
      }
      int res=0,mx=0;
      
      for(int i=0;i<n;i++){
          if(ed[i]>=mx){
              mx=ed[i];
              res=i;
          }
          
      }
      return res;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends