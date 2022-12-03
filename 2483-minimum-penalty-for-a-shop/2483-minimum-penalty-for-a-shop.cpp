class Solution {
public:
    int bestClosingTime(string customers) {
        // find the prefix count of Y and N
      int n = customers.length();
      if(n==0)return n;
      vector<int>prefix(n),suffix(n);
      int ct=0;
      for(int i=0;i<n;i++){

        if(customers[i]=='N')ct++;
                prefix[i]=ct;
      }
      ct=0;
        for(int i=n-1;i>=0;i--){
          if(customers[i]=='Y')ct++;
                suffix[i]=ct;
      }
      
      vector<int>penalty;
      int count_of_N=0;
      for(int i=0;i<n;i++){
        int x=prefix[i]+suffix[i];
        if(customers[i]=='N'){
          count_of_N++;
          x--;
        }
        penalty.push_back(x);
      }
      if(count_of_N==n)
        return 0;
      penalty.push_back(count_of_N);
      
      
      // for(auto in:penalty)cout<<in<<" ";
      
      pair<int,int>p;
      p.first=penalty[0];
      p.second=0;
      for(int i=0;i<penalty.size();i++){
        if(penalty[i]<p.first){
          p.first=penalty[i];
          p.second=i;
        }
      }
      
      return p.second;
    }
};