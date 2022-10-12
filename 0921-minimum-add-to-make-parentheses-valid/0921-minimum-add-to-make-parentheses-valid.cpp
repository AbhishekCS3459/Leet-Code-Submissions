class Solution {
public:
    stack<char>st;
    void remove_valid(string &s){
        cout<<s<<endl;
        for (int i=0;i<s.length();i++){
            char ch=s[i];
            if(!st.empty() &&( ch==')' && st.top()=='(' )   ){
                
                // while(!st.empty() && ( st.top()=='('&& ch==')'))st.pop();
                 st.pop();
                
        }
        else
        st.push(ch);
        
        }
        
    }
    int minAddToMakeValid(string s) {
        remove_valid(s);
        // cout<<st.top();
        return st.size();
    }
};