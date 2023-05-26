//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
   bool isValid(int arr[], int n, int m, int limit) {
    int s = 0;
    int k = 1;
    for (int i = 0; i < n; i++) {
            if(arr[i]>limit){
                return false ;
            }else{
                s += arr[i];
        if (s > limit) {
            s = arr[i];
            k++;
        }
        if (k > m) {
            return false;
        }
    }

        
    }
    return true;
}

int findPages(int A[], int N, int M) {
    int mx = INT_MIN;
    int sum = 0;
    if(N<M)return -1;
    for (int i = 0; i < N; i++) {
        sum += A[i];
        mx = max(mx, A[i]);
    }
    int s = mx; // Minimum possible value is the maximum element in the array
    int e = sum; // Maximum possible value is the sum of all elements in the array
    int res = -1;
    while (s <= e) {
        int mid = (s + (e) )/ 2;
        if (isValid(A, N, M, mid)) {
            res = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return res;
}


};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends