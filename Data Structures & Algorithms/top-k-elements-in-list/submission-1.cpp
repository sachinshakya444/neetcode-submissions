class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int val: nums)
        {
            mp[val]++;
        }
        vector <vector<int>> bucket(nums.size()+1);
        for(auto& pair:mp)
        {
            bucket[pair.second].push_back(pair.first);
        }
        vector <int> result;
        for(int i = bucket.size()-1; i>=0 && result.size()<k; i--)
        {
            for(int val:bucket[i])
            {
                result.push_back(val);
            }
        }
        return result;
    }
};
