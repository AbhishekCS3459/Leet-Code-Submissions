class Solution {
public:
    int reverse(int x) {
     
        long reverse_num=0;
        
        while(x!=0){
            int digit=x%10;
            reverse_num=reverse_num*10+digit;
            x=x/10;
            
        }
        if(reverse_num>INT_MAX || reverse_num<INT_MIN )return 0;
        
        return reverse_num;
    }
};