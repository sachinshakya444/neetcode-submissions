class Solution {
public:
    int maxArea(vector<int>& heights) {
        int j=0;
        int k=heights.size()-1;
        int maxVol = 0;

        while(j<k)
        {
            int minvol = (k-j)*min(heights[k],heights[j]);
            if(maxVol<minvol)
                maxVol = minvol;
            if(heights[k]>heights[j])
            j++;
            else if(heights[k]<=heights[j])
            k--;
        }
        return maxVol;
    }
};
