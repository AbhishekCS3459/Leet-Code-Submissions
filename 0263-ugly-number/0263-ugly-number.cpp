class Solution {
public:
    bool isUgly(int n) {
      // if prime factors of the given number is other than 2,3 or 5 is called ugly number
       if(n==1)return true;
        vector<int>v;
        for(int i=2;i<=sqrt(n);i++){
            
            while(n%i==0){
                v.push_back(i);
                n=n/i;
               // v.push_back(n/i);
            }
            
        }
        if(n!=1)
        v.push_back(n);

bool flag=true;
        
        for(auto in:v){
            if(in==2 || in==3 || in==5 )
                continue;
            else
                flag=false;
        }
        
        for(auto in:v){
            cout<<in<<" ";
        }
        return flag;
        
    }
};