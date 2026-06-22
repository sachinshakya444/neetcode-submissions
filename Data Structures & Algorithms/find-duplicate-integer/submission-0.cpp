class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int start=0,next=0;
        while(true)
        {
            start=nums[start];
            next=nums[nums[next]];
            if(start==next)
            break;
        }
        next=0;
        while(true)
        {
            start = nums[start];
            next = nums[next];
            if(start==next)
            break;
        }
        return start;

    }
};