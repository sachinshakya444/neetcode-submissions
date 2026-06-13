class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int n = s.length();
        int maxlength = 0;
        unordered_set <char> seen;
        while(right<n)
        {
            while(seen.count(s[right]))
            {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            int length = right-left+1;
            maxlength = max(maxlength,length);
            right++;
        }
        return maxlength;
    }
};
