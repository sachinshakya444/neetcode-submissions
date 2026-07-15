class KthLargest {
        priority_queue<int,vector<int>,greater<int>> p;
        int _k;
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for(int i=0;i<nums.size();i++)
        {
            p.push(nums[i]);
            if(p.size()>_k)
            p.pop();
        }
    }
    
    int add(int val) {
        p.push(val);
        if(p.size()>_k)
        p.pop();
        return p.top();
    }
};
