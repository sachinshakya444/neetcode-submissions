class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> seen;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int compliment = target - nums[i];
            if(!seen.count(compliment))
            {
                seen[nums[i]] = i;
            }
            else
            {
                ans.push_back(seen[compliment]);
                ans.push_back(i);
                return ans;
            }
        }
        return {};
   }
};
