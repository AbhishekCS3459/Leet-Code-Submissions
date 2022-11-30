class Solution {
public:
     bool isSubSequence(string A, string B) 
       {
        // code here
        int i=0,j=0;
        int n=A.length();
        int m= B.length();
        while(i<n && j<m){
            if(A[i]==B[j])i++;
            j++;
        }
        return i==n;
    }
    int appendCharacters(string s, string t) {
     
        int i=0,j=0;
        int n=s.length();
        int m= t.length();
        while(i<n && j<m){
            if(s[i]==t[j])
            {i++;
             j++;
            }
          else
            i++;
        }
       return m-j;    
      
      
    }
};