class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //Transpose

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            swap(matrix[i][j],matrix[j][i]);
        }

        //Reverse
        for(int i=0;i<n;i++)
        {
            int start=0;
            for(int j=n-1;j>=0;j--)
            {
                if(start<j)
                {
                swap(matrix[i][start],matrix[i][j]);
                start++;
                }
            }
        }

    }
};
