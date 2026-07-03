class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> result(n+1);
        for(int i = 0;i<=n;i++)
        {
            int num = i;
            result[i] = result[i/2]+(i%2); //DP
        }
        return result;
    }
};
