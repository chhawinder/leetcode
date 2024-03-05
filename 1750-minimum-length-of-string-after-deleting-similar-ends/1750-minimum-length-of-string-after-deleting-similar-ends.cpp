class Solution {
public:
    int minimumLength(string s) {
        
        int i=0,j=s.size()-1;
        while(i<=j){
            char ch1 = s[i];
            char ch2= s[j];
            if(i==j){
                return 1;
            }
            if(ch1!=ch2)break;
            while(i<=j&&s[i]==ch1)i++;
            
             while(i<=j&&s[j]==ch2)j--;
            // if(i==j){
            //     return 1;
            // }
        }
        return j-i+1;
        
    }
};