class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>res;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="/"||tokens[i]=="*"||tokens[i]=="-"||tokens[i]=="+"){
                int f=res.top();res.pop();
                int s=res.top();res.pop();
                if(tokens[i]=="/"){
                    res.push(s/f);
                }else if(tokens[i]=="*"){
                    res.push(s*f);
                }else if(tokens[i]=="-"){
                    res.push(s-f);
                }else{
                    res.push(s+f); 
                }
            }else{
                int k=stoi(tokens[i]);
                res.push(k);
            }
        }
        return res.top();
    }
};