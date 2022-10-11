class Solution {
public:
    int trap(vector<int>& height) {
     stack<int>s;
        int curr=0;
    
        int ans=0;
        while(curr<height.size()){
            
            // check for the bigger element than curr element
            while(!s.empty()&& height[curr]>height[s.top()]){
                int top=s.top();
                s.pop();
                if(s.empty())break;
              int  distance =curr-s.top()-1;
               int h = min(height[curr],height[s.top()])-height[top];
                ans+=h*distance;
            }
            
            s.push(curr++);
        }
        return ans;
    }
};