//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int N, long long int K) {
                                                 queue<int>q;
                                                 for(int i=0;i<K;i++){
                                                     if(a[i]<0)q.push(i);
                                                 }
                                                 
                                                 int i=0,j=K;
                                                 vector<long long>res;
                                                 while(j<N){
                                                     
                                                     if(q.size()==0){
                                                         res.push_back(0);
                                                     }else
                                                     {
                                                          int temp=q.front();
                                                     if(temp==i)q.pop();
                                                     res.push_back(a[temp]);
                                                     }
                                                    
                                                     if(a[j]<0)q.push(j);
                                                     i++;j++;
                                                 }
                                                  if(q.size()==0){
                                                         res.push_back(0);
                                                     }else
                                                     {
                                                          int temp=q.front();
                                                     if(temp==i)q.pop();
                                                     res.push_back(a[temp]);
                                                     }
                                                 return res;
                                                 
 }