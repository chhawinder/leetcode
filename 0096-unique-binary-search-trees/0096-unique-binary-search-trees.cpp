class Solution {
public:
    int numTrees(int n) {
        if(n==0||n==1)return 1;
        int k=n-1;
        int low=0;
        int high=k;
        int res=0;
        while(low<=high){
            if(low==high){
                res+=numTrees(low)*numTrees(low);
            }else{
               res+=2*numTrees(low)*numTrees(high);
             
            }
            low++;high--;
        }
        return res;
        
    }
};