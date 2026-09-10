class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<bool>visited(n,false);
        vector<vector<pair<int, int>>> adj(n);
        vector<int> distance(n, INT_MAX);
        for (auto& i : times) {
            int u = i[0] - 1;
            int v = i[1] - 1;
            int w = i[2];
            adj[u].push_back({w, v});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0,k-1});
        distance[k-1] = 0;
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            if (visited[temp.second]) {
                continue;
            }
            visited[temp.second] = true;
            for (auto& j : adj[temp.second]) {
                int weight = j.first;
                int to = j.second;
                if (!visited[to] && distance[to] > temp.first + weight) {
                    distance[to] = temp.first + weight;
                    pq.push({distance[to], to});
                }
            }
        }
        int ans = -1;
        for (int i : distance) {
            if (i == INT_MAX)
                return -1;
            ans=max(ans,i);
        }
        return ans;
    }
};