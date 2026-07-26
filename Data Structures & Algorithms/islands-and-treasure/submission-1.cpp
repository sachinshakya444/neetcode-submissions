class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                q.push({i,j});
            }
        }

        while(!q.empty())
        {
            pair<int,int> current = q.front();
            q.pop();
            int x = current.first;
            int y = current.second;
            // up
            if(x-1>=0 && grid[x-1][y]>grid[x][y]+1)
            {
                grid[x-1][y] = grid[x][y]+1;
                q.push({x-1,y});
            }
            //down
            if(x+1<m && grid[x+1][y]>grid[x][y]+1)
            {
                grid[x+1][y] = grid[x][y]+1;
                q.push({x+1,y});
            }
            //left
            if(y-1>=0 && grid[x][y-1]>grid[x][y]+1)
            {
                grid[x][y-1] = grid[x][y]+1;
                q.push({x,y-1});
            }
            //right
            if(y+1<n && grid[x][y+1]>grid[x][y]+1)
            {
                grid[x][y+1] = grid[x][y]+1;
                q.push({x,y+1});
            }
        }
    }
};
