class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x)
        {
            if(result>2147483647/10 || result<-2147483647/10)
            return 0;
            result = result*10 + x%10;
            x = x/10;            
        }
        return result;
    }
};
