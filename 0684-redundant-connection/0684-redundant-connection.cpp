class Solution {
public:

    bool bfs(int src, int tar, vector<vector<int>>& adjLs, vector<bool> vis){
        vis[src] = true;
        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(node == tar) return true;

            for(int it : adjLs[node]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push(it);
                }
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
                if(bfs(u, v, adjLs, vis)){
                    return edge;
                }
            }

            adjLs[u].push_back(v);
            adjLs[v].push_back(u);
        }
        return {};
    }
};