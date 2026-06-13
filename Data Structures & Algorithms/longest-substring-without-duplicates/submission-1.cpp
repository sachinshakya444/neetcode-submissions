class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;  // char → last index
        int left = 0;
        int maxlength = 0;

        for(int right = 0; right < s.length(); right++)
        {
            if(mp.count(s[right]) && mp[s[right]] >= left)
            {
                left = mp[s[right]] + 1;  // seedha jump! ✅
            }
            mp[s[right]] = right;  // index update karo
            maxlength = max(maxlength, right - left + 1);
        }
        return maxlength;
    }
};