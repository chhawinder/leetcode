class Solution {
public:
    
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if(a==e||b==f){
            if(a==e){
                if(b>f){
                    if(!(a==c&&(b>d&&d>f)))return 1;
                }
                if(f>b){
                    if(!(a==c&&(b<d&&d<f)))return 1;
                }
            }
            
            if(b==f){
                if(a<e){
                    if(!(b==d&&(a<c&&c<e)))return 1;
                }
                if(a>e){
                    if(!(b==d&&(a>c&&c>e)))return 1;
                }
            }
                
        }
            
        int i=e,j=f;
        // travel left
        while(i>0&&j<=8){
            if(i==a&&j==b)break;
            if(i==c&&j==d)return 1;
            i--;j++;
        }
        i=e,j=f;
        // travel left
        while(i<=8&&j<=8){
            if(i==a&&j==b)break;
            if(i==c&&j==d)return 1;
            i++;j++;
        }
        i=e,j=f;
        // travel left
        while(i>0&&j>0){
            if(i==a&&j==b)break;
            if(i==c&&j==d)return 1;
            i--;j--;
        }
        i=e,j=f;
        // travel left
        while(i<=8&&j>0){
            if(i==a&&j==b)break;
            if(i==c&&j==d)return 1;
            i++;j--;
        }
        
        return 2;
        
    }
};