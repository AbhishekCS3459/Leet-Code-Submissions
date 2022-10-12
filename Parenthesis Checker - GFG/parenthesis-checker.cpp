//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    bool matching(char ch,char st){
        if((ch==']'&& st=='[')||(ch==')'&&st=='(') || ch=='}'&&st=='{')
        return true;
        else
        return false;
    }
    //Function to check if brackets are balanced or not.
    stack<char>s;
    
    bool ispar(string x)
    {
        // Your code here
        for(int i=0;i<x.length();i++){
            
            char ch=x[i];
            if(ch=='{'|| ch=='('||ch=='[')s.push(ch);
            
            else{
              
                if(!s.empty()){
                    if(matching(ch,s.top()))
                    s.pop();
                    
                    else
                    return false;
                }
                else
                return false;
                
            }
        }
        
        if(s.empty())return true;
        else
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends