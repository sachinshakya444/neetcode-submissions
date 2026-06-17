class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
        
        vector <int> count1(26,0);
        vector <int> count2(26,0);

        for(char c:s1)
        count1[c-'a']++;

        int matches = 0;
        for(int i=0;i<26;i++)
        {
            if(count1[i]==count2[i])
            matches++;
        }

        for(int right = 0;right<s2.size();right++)
        {
            int idx = s2[right]-'a';
        count2[idx]++;

        if(count2[idx]==count1[idx])
        matches++;
        else if(count2[idx]==count1[idx]+1)
        matches--;

        if(right>=s1.size())
        {
            int l = s2[right - s1.size()] - 'a';
            count2[l]--;
            if(count2[l]==count1[l])
            matches++;
            else if(count2[l]==count1[l]-1)
            matches--;
        }

        if(matches==26)
        return true;

        }

        return false;

    }
};
