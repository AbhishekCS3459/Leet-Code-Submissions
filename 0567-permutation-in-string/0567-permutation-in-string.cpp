class Solution {
public:
    // This question is the sub problem of count anagram of a string
    // uses sliding window
    map<char,int>p_hash;
    bool checkInclusion(string s1, string s2) {
                    for(int i=0;i<s1.size();i++){
            p_hash[s1[i]]++;
        }
        
        int i=0;
        int j=0;
        vector<int>ans;
        int k=s1.size();
        
        int count=p_hash.size();
        
        while(j<s2.length()){
            if(p_hash.find(s2[j])!=p_hash.end() ){
                p_hash[s2[j]]--;
                
                if(p_hash[s2[j]]==0)count--;
            }
            if(j-i+1<k)j++;
            
            else if(j-i+1==k){
                if(count==0)ans.push_back(i);
                if(p_hash.find(s2[i]) !=p_hash.end() ){
                    p_hash[s2[i]]++;
                    if(p_hash[s2[i]]==1)
                    count++;
                }
                i++;
                j++;
            }
            
        }
        if(ans.size()!=0)
        return true;
        else
            return false;
          
        
        
    }
};