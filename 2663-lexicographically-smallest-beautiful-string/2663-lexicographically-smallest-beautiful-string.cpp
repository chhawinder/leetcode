class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }
        return true;
    }

    bool hasPalindromeSubstring(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && s[j] != s[i]) {
                j++;
            }
            if (j < n && isPalindrome(s.substr(i, j - i + 1))) {
                return true;
            }
        }
        return false;
    }

    string smallestBeautifulString(string s, int k) {
        int n = s.length();
        int pos=-1;
        for(int i=n-1;i>=0&&pos<0;i--){
            int cur=s[i]-'a';
            cur++;
            while(cur<k&&pos<0){
                bool isPal=false;
                if(i-1>=0 &&(s[i-1]-'a')==cur)isPal=true;
                if(i-2>=0&&(s[i-2]-'a')==cur)isPal=true;
                if(isPal!=true){
                    s[i]=char(cur+'a');
                    pos=i;
                }
                cur++;
                
            }
        }
        
        if(pos<0)return "";
        
        for(int i=pos+1;i<n;i++){
            for(int j=0;j<3;j++){
                bool isPal=false;
                if(i-1>=0&&(s[i-1]-'a')==j)isPal=true;
                if(i-2>=0&&(s[i-2]-'a')==j)isPal=true;
                if(isPal!=true){
                    s[i]=char(j+'a');
                    break;
                }
                
            }
        }
        return s;
        
        
        
    }
        
};