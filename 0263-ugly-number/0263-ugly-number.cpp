class Solution {
public:
    bool isUgly(int n) {
        if(n<1)return false;
        vector<int>primes={2,3,5};
        for(auto in:primes){
            while(n%in==0){
                n/=in;
            }
        }
        if(n==1)return true;
        else
            return false;
    }
};