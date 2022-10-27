class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length()==0)return 0;
       stack<int>st;
        if(s.length()==1 || s.length()==0)return 0;
        st.push(-1);
        int len=0,mx=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else
                {
                    len=i-st.top();
                 if(len>=mx)mx=len;
                }
                
            }
            else
                st.push(i);
        }
        cout<<st.size()<<" ";
        return mx;
    }
};