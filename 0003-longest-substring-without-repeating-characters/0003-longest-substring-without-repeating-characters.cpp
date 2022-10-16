class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//         map<char,int>m;
//     int count=m.size();
//      int i=0,j=0,mx=INT_MIN;
        
//      while(j<s.length()){
//           m[s[j]]++;
//           if(m.size()<j-i+1)j++;
//           else if(m.size()==j-i+1){
//               mx=max(mx,j-i+1);
//               j++;
//           }
//          else{
//              while(m.size()>j-i+1){
//              m[s[i]]--;
            
//               if(m[s[i]]==0)m.erase(s[i]);   
//               i++;
                 
//              }
             
//              j++;
//          }   
         
//      }
//     return mx;
        
      
             int i=0,j=0,mx=INT_MIN,k;
        
        
     map<char,int>m;
     while(j<s.length()){
         k=j-i+1;
         m[s[j]]++;
         // if(m.size()<k){
         //     j++;
         // }
          if(m.size()==k){
             mx=max(mx,j-i+1);
             j++;
         }
        else if(m.size()<j-i+1){
             while(m.size()<j-i+1){
                 m[s[i]]--;
                 if(m[s[i]]==0)m.erase(s[i]);
                 i++;
             }
            
            j++; 
         }
         
     }
     if(mx==INT_MIN)mx=max(mx,0);
     return mx;
    }
};