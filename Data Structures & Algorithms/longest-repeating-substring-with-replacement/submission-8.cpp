class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int n=s.length();
        int count[26]={0};
        int maxlen=0;
        int mostfrequent=0;
        for(int right=0;right<n;right++)
        {
            count[s[right]-'A']++;
            mostfrequent = max(mostfrequent,count[s[right]-'A']);
            while((right-left+1)-mostfrequent>k)
            {
                count[s[left]-'A']--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};
