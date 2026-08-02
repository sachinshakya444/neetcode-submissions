class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size()!=n-1)
        return false;

        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        vector<bool> visited(n,false);
        q.push(0);
        visited[0] = true;
        int count = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            for(int j=0;j<adj[node].size();j++)
            {
                int neighbour = adj[node][j];
                if(!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        return count == n;
    }
};
