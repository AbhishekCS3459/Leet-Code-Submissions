class Solution {
public:
    vector<int>powers;
    const int m=1e9+7;
   void making_of_powers(int n)
   {


                 for(int i = 0; i < 32; ++i){
            if((n & (1<<i)) != 0) powers.push_back(1<<i);}
// for(auto in:ans)cout<<in<<" ";


}


    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans,bint;
        making_of_powers(n);
        for(auto in:powers)
            cout<<in<<" ";
        // }
        // cout<<'Bint';
        //   for(int i = 0; i < 32; ++i){
        //     if((n & (1<<i)) != 0) bint.push_back(1<<i);
        // }
        
         for(auto q: queries){
            int i = q[0];
            long p = powers[i++];
            while(i <= q[1]){
                p = (p * powers[i++])%m;
            }
            ans.push_back(p);
        }
       return ans; 
    }
};