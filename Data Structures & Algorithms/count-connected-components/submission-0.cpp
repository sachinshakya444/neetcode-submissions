class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);
        int count = 0;
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            count++;

            queue<int> q;
            q.push(i);
            visited[i] = true;

            while(!q.empty())
            {
                int node = q.front();
                q.pop();

                for(int j=0;j<adj[node].size();j++)
                {
                    int neighbor = adj[node][j];
                    if(!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
        return count;
    }
};
