class Solution {
public:
    unordered_map<char,int>p_hash;
    vector<int> findAnagrams(string s, string p) {
        for(int i=0;i<p.size();i++){
            p_hash[p[i]]++;
        }
        
        int i=0;
        int j=0;
        vector<int>ans;
        int k=p.size();
        
        int count=p_hash.size();
        
        while(j<s.length()){
            if(p_hash.find(s[j])!=p_hash.end() ){
                p_hash[s[j]]--;
                
                if(p_hash[s[j]]==0)count--;
            }
            if(j-i+1<k)j++;
            
            else if(j-i+1==k){
                if(count==0)ans.push_back(i);
                if(p_hash.find(s[i]) !=p_hash.end() ){
                    p_hash[s[i]]++;
                    if(p_hash[s[i]]==1)
                    count++;
                }
                i++;
                j++;
            }
            
        }
        return ans;
        
    }
};