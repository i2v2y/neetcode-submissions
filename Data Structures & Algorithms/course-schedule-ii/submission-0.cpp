class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        for (int c = 0; c < numCourses; c++) {
            if (indegree[c] == 0) q.push(c);
        }

        vector<int> out;
        int finished = 0;
        while (!q.empty()) {
            int c = q.front();
            out.push_back(c);
            q.pop();
            finished++;

            for (int n : adj[c]) {
                indegree[n]--;
                if (indegree[n] == 0) q.push(n);
            }
        }

        if (finished == numCourses) return out;
        return {};
    }
};
