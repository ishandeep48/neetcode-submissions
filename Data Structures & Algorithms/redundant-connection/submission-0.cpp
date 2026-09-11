class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    bool merge(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py)return false;
        parent[px]=py;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
        for(auto&i:edges){
            int u=i[0]-1;
            int v=i[1]-1;
            if(!merge(u,v))return{u+1,v+1};
        }
        return {};

    }
};