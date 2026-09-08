class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto&edge : prerequisites) {
            int from = edge[1];
            int to = edge[0];
            adj[from].push_back(to);
        }
        vector<int> ingress(numCourses);
        for (const auto&i : adj) {
            for (int j : i)
                ingress[j]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (ingress[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            for (int&i : adj[temp]) {
                ingress[i]--;
                if (ingress[i] == 0)
                    q.push(i);
            }
        }
        for (int&i : ingress)
            if (i > 0)
                return false;
        return true;
    }
};