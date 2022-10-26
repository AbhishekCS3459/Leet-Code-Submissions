class Solution {
public:
    bool isValid(string s) {
       // first we will insert the charracter into the stack
        stack<char>st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];

        // new we will check one by one 
   // whenever we face an closing bracket check and remove that closing crossponding to the opening ones
            if(ch=='{'||ch=='['||ch=='('){
                // these are opening brackets so we will insert into stack
                st.push(ch);
            }
            else   // it is a closing brackets
            {
                
                 if(!st.empty()){
                     char ch=s[i];
                     if(ch==']'&& st.top()=='['|| ch==')'&&st.top()=='('||ch=='}'&& st.top()=='{'){
                         st.pop();
                     }
                     else
                         return false;
                 } 
                else
                    return false;
            }
        
        }
       
        
        if(st.empty())return true;
        else
            return false;
    }
};