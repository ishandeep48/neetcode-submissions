class Solution {
   public:
    vector<int> parent;
    int findParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }
    bool merge(int x, int y) {
        int pX = findParent(x);
        int pY = findParent(y);
        if (pX == pY) return false;
        parent[pX] = parent[pY];
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
         if (edges.size() != n - 1)
            return false;
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto& i : edges) {
            int u = i[0];
            int v = i[1];
            if(!merge(u,v))return false;
        }
        return true;
    }
};
