class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
      vector<pair<int,int>>m;
      int n=skill.size();
      
      int k=n/2;
      int t=skill[0]+skill[n-1];
      for(int i=0;i<k;i++){
        int ct=skill[i]+skill[n-i-1];
        if(t!=ct)return -1;
        m.push_back( {skill[i],skill[n-i-1]} );
      }
      long long ans=0;
      for(auto in:m){
        ans+=in.first*in.second;
      }
      return ans;
    }
};