class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDeg(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];

            adj[prereq].push_back(course);
            inDeg[course]++;
        }
        queue<int> q;
        for(int i=0;i<inDeg.size();i++)
        {
            if(!inDeg[i])
            q.push(i);
        }
        int count = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for(int j=0;j<adj[node].size();j++)
            {
                inDeg[adj[node][j]]--;
                if(!inDeg[adj[node][j]])
                q.push(adj[node][j]);
            }
        }
        return count==numCourses;
    }
};
