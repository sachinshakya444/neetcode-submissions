class Solution {
public:
    bool hasPathBfs(int source,int target,vector<vector<int>> &adj,int n)
    {
        vector<bool> visited(n+1,false);
        queue<int> q;
        visited[source] = true;
        q.push(source);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            if(node==target)
            return true;

            for(int j=0;j<adj[node].size();j++)
            {
                if(!visited[adj[node][j]])
                {
                visited[adj[node][j]] = true;
                q.push(adj[node][j]);
                }
            }
        }
        return false;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            if(!adj[u].empty() && !adj[v].empty())
            {
                if(hasPathBfs(u,v,adj,n))
                return edges[i];
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};
