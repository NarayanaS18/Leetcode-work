class Solution {
private:
    vector<int> parent;
public:

    int find(int node){
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }

    bool unionNodes(int u, int v){
        int rootU = find(u);
        int rootV = find(v);

        if(rootU == rootV) return false;
        parent[rootU] = rootV;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        parent.resize(V+1);

        for(int i=1; i<=V; i++){
            parent[i] = i;
        }

        for(auto& edge : edges){
            int u = edge[0], v = edge[1];
            if(!unionNodes(u, v)) return edge;
        }

        return {};
    }
};