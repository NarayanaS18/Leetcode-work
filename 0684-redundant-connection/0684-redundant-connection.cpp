class Solution {
public:

    bool dfs(int src, int tar, vector<vector<int>>& adjLs, vector<bool>& vis){
        if(src == tar) return true;
        vis[src] = true;

        for(int it : adjLs[src]){
            if(!vis[it]){
                if(dfs(it, tar, adjLs, vis)) return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        vector<vector<int>> adjLs(V+1);

        for(auto &edge : edges){
            int u = edge[0], v = edge[1];
            
            if(!adjLs[u].empty() && !adjLs[v].empty()){
                vector<bool> vis(V+1, false);
                if(dfs(u, v, adjLs, vis)){
                    return edge;
                }
            }

            adjLs[u].push_back(v);
            adjLs[v].push_back(u);
        }
        return {};
    }
};