class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words; // To store the words
    stringstream ss(sentence); 
    string word;
    
    // Extract each word and push it into the vector
    while (ss >> word) {
        words.push_back(word);
    }
        
        if(words.size()==1){
            string word=words[0];
            if(word[0]==word[word.size()-1])return true;
            else return false;
        }
        // char s=words[0][0];
        for(int i=1;i<words.size();i++){
            int n=words[i-1].size()-1;
            if(words[i][0]!=words[i-1][n])return false;
        }
        int n=words[words.size()-1].size()-1;
        if(words[words.size()-1][n]!=words[0][0])return false;
        return true;
        
        // if(sentence)
        
    }
};