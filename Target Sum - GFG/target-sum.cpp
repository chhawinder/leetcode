//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  int help(vector<int>&A ,int target,int n,int s){
      if(n==0){
          int res=0;
          if(s-A[n]==target)res++;
          if(s+A[n]==target)res++;
          return res;
      }
      int neg=help(A,target,n-1,s-A[n]);
      int pos=help(A,target,n-1,s+A[n]);
      return neg+pos;
  }
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        return help(A,target,A.size()-1,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends