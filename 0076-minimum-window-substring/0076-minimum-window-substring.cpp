class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        int j=0,i=0;
        map<char,int>m;
        for(auto in:t)m[in]++;
        int ct=m.size();
        int mn=INT_MAX;
        while(j<s.length()){
            
            if(m.find(s[j]) !=m.end() ){
                m[s[j]]--;
                
                if(m[s[j]]==0)ct--;}
                j++;
            
                
                while(ct==0){
                 
                       if(j-i < mn){
                    mn = j - i;
                    ans = s.substr(i, j - i); 
                }
                    if(m.find(s[i])!=m.end()){
                        m[s[i]]++;
                        if(m[s[i]]>0)ct++;
                        
                    }
                    i++;
                }
                
            
        }
        return ans;
    }
};