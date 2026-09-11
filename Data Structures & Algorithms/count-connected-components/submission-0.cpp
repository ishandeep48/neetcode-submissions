class Solution {
public:
    vector<int>parent;
    int total;
    int find(int x){
        if(x==parent[x])return x;
        return parent[x]=find(parent[x]);
    }
    void merge(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py)return;
        parent[px]=py;
        total--;
        return ;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        total=n;
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto&i:edges){
            int u=i[0];
            int v=i[1];
            merge(u,v);
        }
        return total;
    }
};
