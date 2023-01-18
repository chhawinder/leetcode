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
    int findTargetSumWays(vector<int>& A, int target) {
        return help(A,target,A.size()-1,0);
    }
};