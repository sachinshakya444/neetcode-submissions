class Solution {
public:
    bool isHappy(int n) {
            int num = n;
        unordered_set <int> mp;
        while(num!=1 && !mp.count(num))   //should be and 
        {
            mp.insert(num);
           int sum = 0;                 // remember to reset this
            while(num)
            {
            int digit = num%10; // should take another variable not this num = num%10;
            sum = sum+(digit*digit);
            num = num/10;
            }
            num = sum;
        }
        if(num==1)
        return true;
        else
        return false;
    }
};
