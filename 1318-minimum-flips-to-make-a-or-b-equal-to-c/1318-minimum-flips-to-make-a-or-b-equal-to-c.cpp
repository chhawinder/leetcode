class Solution {
public:
    int minFlips(int a, int b, int c) {
        
         string astring = bitset<sizeof(int) * 8>(a).to_string();
         astring = astring.substr(astring.find('1'));
        
        string bstring=bitset<sizeof(int)*8>(b).to_string();
        bstring=bstring.substr(bstring.find('1'));
        
        string cs=bitset<sizeof(int)*8>(c).to_string();
        cs=cs.substr(cs.find('1'));
        
        int ml=max(astring.size(),max(bstring.size(),cs.size()));
        while(astring.size()!=ml){
            astring='0'+astring;
        }
         while(bstring.size()!=ml){
            bstring='0'+bstring;
        }
         while(cs.size()!=ml){
            cs='0'+cs;
        }
        cout<<astring<<" "<<bstring<<" "<<cs<<endl;
        int count=0;
        for(int i=0;i<cs.size();i++){
            if(cs[i]=='0'){
                if(astring[i]=='1')count++;
                if(bstring[i]=='1')count++;
            }else{
                if(astring[i]=='0'&&bstring[i]=='0'){
                    count++;
                }
            }
        }
        return count;
        
    }
};