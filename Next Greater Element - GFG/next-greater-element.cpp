//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        vector<long long int>r;
        stack<long long int>s;
        for(int i=n-1;i>=0;i--){
            while(s.size()!=0){
                if(s.top()<arr[i])s.pop();
                else{
                    r.push_back(s.top());
                    s.push(arr[i]);
                    break;
                }
            }
            if(s.size()==0){
                r.push_back(-1);
                s.push(arr[i]);
            }
        }
        reverse(r.begin(),r.end());
        return r;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends