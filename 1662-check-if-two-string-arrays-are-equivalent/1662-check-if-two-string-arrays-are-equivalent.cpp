class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string m="";
        for(auto in :word1){
            m+=in;
        }
        string t="";
        for(auto in:word2){
            t+=in;
        }
        
     if(m==t)
        return true;
        else
            return false;

     
        
    }
};